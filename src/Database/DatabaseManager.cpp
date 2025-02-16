#include <Database/DatabaseManager.hpp>

DatabaseManager::DatabaseManager()
{
    dbClient = orm::DbClient::newPgClient(
        "host=localhost "
        "port=5432 "
        "dbname=schedule_db "
        "connect_timeout=10 "
        "password=test "
        "user=schedule_admin",
        1
    );

    // Move elsewhere?
    dbClient->execSqlSync(
        "CREATE TABLE IF NOT EXISTS test("
            "id SERIAL PRIMARY KEY, "
            "name VARCHAR(255)"
        ");"
    );
}

orm::DbClientPtr DatabaseManager::getDbClient()
{
    return dbClient;
}
