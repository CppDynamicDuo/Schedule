#include <TestController.hpp>

void TestController::asyncHandleHttpRequest(
    const drogon::HttpRequestPtr& req,
    std::function<void (const drogon::HttpResponsePtr&)>&& callback
)
{
    Json::Value ret;
    ret["message"] = "Hello, World!";

    auto res = drogon::HttpResponse::newHttpJsonResponse(ret);

    callback(res);
}
