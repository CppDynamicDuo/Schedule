#pragma once
#include <drogon/HttpController.h>
#include <drogon/orm/DbClient.h>

#include <jwt-cpp/jwt.h>

using namespace drogon;

using Callback = std::function<void(const HttpResponsePtr&)>;

class LoginController : public HttpController<LoginController>
{
public:
    void login(const HttpRequestPtr& req, Callback&& callback);

public:
    METHOD_LIST_BEGIN

        ADD_METHOD_TO(LoginController::login, "/login", Post);

    METHOD_LIST_END

private:
    bool validateUser(std::shared_ptr<Json::Value> json);
};

