#pragma once
#include <drogon/HttpSimpleController.h>

class TestController : public drogon::HttpSimpleController<TestController>
{
public:
    void asyncHandleHttpRequest(
        const drogon::HttpRequestPtr& req,
        std::function<void (const drogon::HttpResponsePtr&)>&& callback
    ) override;

    //////////////////////////////

    PATH_LIST_BEGIN
        
        PATH_ADD("/", drogon::Get);
    
    PATH_LIST_END
};
