#include <drogon/drogon.h>

using namespace drogon;
using namespace trantor;

using namespace std::chrono_literals;

int main()
{
    app()
        .setLogPath("./")
        .setLogLevel(Logger::kWarn)
        .addListener("0.0.0.0", 8080)
        .setThreadNum(16)
        // .enableRunAsDaemon()
        .enableSession(1min)
        .run();
}
