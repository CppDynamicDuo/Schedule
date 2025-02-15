#include <Controllers/TestController.hpp>
#include <DatabaseManager.hpp>

#include <format>

void TestController::greetUser(
    const HttpRequestPtr& req,
    std::function<void (const HttpResponsePtr&)>&& callback,
    
    const std::string& name
)
{
    DatabaseManager::get().getDbClient()->execSqlAsyncFuture("INSERT INTO test (name) VALUES ($1);", name);

    Json::Value json;
    json["message"] = std::format("Hello, {}?", name);

    auto res = HttpResponse::newHttpJsonResponse(json);

    callback(res);
}
