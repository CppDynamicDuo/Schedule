#include <Controllers/TestController.hpp>

#include <format>

void TestController::greetUser(
    const HttpRequestPtr& req,
    std::function<void (const HttpResponsePtr&)>&& callback,
    
    const std::string& name
)
{
    Json::Value json;
    json["message"] = std::format("Hello, {}!", name);

    auto res = HttpResponse::newHttpJsonResponse(json);

    callback(res);
}
