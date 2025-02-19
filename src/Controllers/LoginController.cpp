#include <Controllers/LoginController.hpp>

void LoginController::login(const HttpRequestPtr& req, Callback&& callback)
{
    auto request = req->getJsonObject();

    if(validateUser(request))
    {
        auto token = jwt::create()
            .set_issuer("auth0")
            .set_type("JWS")
            .set_payload_claim(
                (*request)["username"].asString(),
                jwt::claim(request->get("username", "").asString())
            )
            .sign(jwt::algorithm::hs256("secret"));

        Json::Value json;
        json["token"] = token;

        callback(HttpResponse::newHttpJsonResponse(json));
    }
    else
    {
        auto response = HttpResponse::newHttpResponse();
        response->setStatusCode(k401Unauthorized);

        callback(response);
    }
}

bool LoginController::validateUser(std::shared_ptr<Json::Value> json)
{
    if(!json)
        return false;

    // Just a placeholder
    return ((*json)["username"] == "amogus" && (*json)["password"] == "test");
}
