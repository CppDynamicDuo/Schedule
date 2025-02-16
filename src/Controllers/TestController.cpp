#include <Controllers/TestController.hpp>
#include <Database/DatabaseManager.hpp>
#include <Models/Test.hpp>

#include <format>

namespace models = drogon_model::schedule_db;

void TestController::greetUser(
    const HttpRequestPtr& req,
    std::function<void (const HttpResponsePtr&)>&& callback,
    
    const std::string& name
)
{
    //DatabaseManager::get().getDbClient()->execSqlAsyncFuture("INSERT INTO test (name) VALUES ($1);", name);
    static auto& mapper = DatabaseManager::get().getMapper<models::Test>();

    Json::Value insertValue;
    insertValue["name"] = name;

    mapper.insertFuture(models::Test(insertValue));

    Json::Value json;
    json["message"] = std::format("Hello, {}?", name);

    auto res = HttpResponse::newHttpJsonResponse(json);

    callback(res);
}
