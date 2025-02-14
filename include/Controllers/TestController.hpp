#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

class TestController : public HttpController<TestController>
{
public:
    void greetUser(
        const HttpRequestPtr& req,
        std::function<void (const HttpResponsePtr&)>&& callback,

        // Method arguments
        const std::string& name
    );

    //////////////////////////////

    METHOD_LIST_BEGIN

        // METHOD_ADD(TestController::greetUser, "/{name}", Get); // localhost:8080/TestController/{name}
        ADD_METHOD_TO(TestController::greetUser, "/test/{name}", Get);

    METHOD_LIST_END
};
