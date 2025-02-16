#include <Controllers/TestController.hpp>
#include <Database/DatabaseManager.hpp>
#include <Models/Test.hpp>

#include <format>

namespace models = drogon_model::schedule_db;

void TestController::get(
    const HttpRequestPtr& req,
    std::function<void (const HttpResponsePtr&)>&& callback
)
{
    static auto& mapper = DatabaseManager::get().getMapper<models::Test>();
    
    auto queryResult = mapper.findAll();

    Json::Value json;
    for(auto& i : queryResult)
        json.append(i.toJson());

    auto res = HttpResponse::newHttpJsonResponse(json);

    callback(res);
}

void TestController::post(
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
    json["message"] = std::format("Value \"{}\" was inserted (asynchronously)", name);

    auto res = HttpResponse::newHttpJsonResponse(json);

    callback(res);
}
