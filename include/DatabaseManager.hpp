#pragma once
#include <Singleton.hpp>

#include <drogon/orm/DbClient.h>

using namespace drogon;

class DatabaseManager : public Singleton<DatabaseManager>
{
public:
    orm::DbClientPtr getDbClient();

private:
    DatabaseManager();

    friend class Singleton<DatabaseManager>;

private:
    orm::DbClientPtr dbClient;

};
