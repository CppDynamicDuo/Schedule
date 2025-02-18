#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

using Callback = std::function<void(const HttpResponsePtr&)>;

class JsonController : public HttpController<JsonController>
{
public:
    void getJson(const HttpRequestPtr& req, Callback&& callback);

    METHOD_LIST_BEGIN

        //METHOD_ADD(JsonController::getJson, "/", Get); // localhost:8080/JsonController/
        ADD_METHOD_TO(JsonController::getJson, "/json/", Get);

    METHOD_LIST_END

};
