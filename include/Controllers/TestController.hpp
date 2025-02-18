#pragma once
#include <drogon/HttpController.h>
#include <drogon/orm/DbClient.h>

using namespace drogon;

using Callback = std::function<void(const HttpResponsePtr&)>;

class TestController : public HttpController<TestController>
{
public:
    // This will return an entire database table in response
    void get(const HttpRequestPtr& req, Callback&& callback);
    
    // This will add a named "user" and his task
    void post(
        const HttpRequestPtr& req,
        Callback&& callback,

        // Method arguments
        const std::string& name,
        const std::string& task
    );

    //////////////////////////////
public:
    METHOD_LIST_BEGIN

        // METHOD_ADD(TestController::greetUser, "/{name}", Get); // localhost:8080/TestController/{name}
        ADD_METHOD_TO(TestController::get, "/test", Get);
        ADD_METHOD_TO(TestController::post, "/test/{name}/{task}", Post);

    METHOD_LIST_END

private:
    void addStudentAndTask(const std::string& name, const std::string& task);
};
