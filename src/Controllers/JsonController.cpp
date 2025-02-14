#include <Controllers/JsonController.hpp>

#include <format>

void JsonController::getJson(
    const HttpRequestPtr& req,
    std::function<void (const HttpResponsePtr&)>&& callback
)
{
    Json::Value json;
    json["message"] = std::format("Hello, {}!", (*req->getJsonObject())["name"].asString());

    auto res = HttpResponse::newHttpJsonResponse(json);

    callback(res);
}
