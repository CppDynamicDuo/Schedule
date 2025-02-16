#pragma once
#include <drogon/HttpController.h>
#include <drogon/orm/DbClient.h>

using namespace drogon;

class TestController : public HttpController<TestController>
{
public:
    // This will return an entire database table in response
    void get(
        const HttpRequestPtr& req,
        std::function<void (const HttpResponsePtr&)>&& callback
    );
    
    // This will add a named "user"
    void post(
        const HttpRequestPtr& req,
        std::function<void (const HttpResponsePtr&)>&& callback,

        // Method arguments
        const std::string& name
    );

    //////////////////////////////

    METHOD_LIST_BEGIN

        // METHOD_ADD(TestController::greetUser, "/{name}", Get); // localhost:8080/TestController/{name}
        ADD_METHOD_TO(TestController::get, "/test", Get);
        ADD_METHOD_TO(TestController::post, "/test/{name}", Post);

    METHOD_LIST_END
};
