#include <Controllers/TestController.hpp>
#include <Database/DatabaseManager.hpp>
//#include <Models/Test.hpp>
#include <Models/Student.hpp>
#include <Models/StudentTask.hpp>

#include <format>

namespace models = drogon_model::schedule_db;

void TestController::get(const HttpRequestPtr& req, Callback&& callback)
{
    static auto dbClient = DatabaseManager::get().getDbClient();
    static auto& mapper = DatabaseManager::get().getMapper<models::StudentTask>();
    
    auto queryResult = mapper.findAll();

    Json::Value json;
    for(auto& i : queryResult)
    {
        json.append(i.toJson());
        json.back()["student_object"] = i.getStudent(dbClient).toJson();
    }

    auto response = HttpResponse::newHttpJsonResponse(json);

    callback(response);
}

void TestController::post(
    const HttpRequestPtr& req, Callback&& callback,

    // Method arguments
    const std::string& name, const std::string& task
)
{
    addStudentAndTask(name, task);

    Json::Value json;
    json["message"] = std::format("Value \"{}\" \"{}\" was inserted (asynchronously)", name, task);

    auto response = HttpResponse::newHttpJsonResponse(json);

    callback(response);
}

void TestController::addStudentAndTask(const std::string& name, const std::string& task)
{
    static auto& studentMapper = DatabaseManager::get().getMapper<models::Student>();
    static auto& taskMapper = DatabaseManager::get().getMapper<models::StudentTask>();

    models::Student student;
    student.setName(name);

    studentMapper.insert(student);

    models::StudentTask studentTask;
    studentTask.setStudentId(student.getPrimaryKey());
    studentTask.setTask(task);

    taskMapper.insert(studentTask);
}
