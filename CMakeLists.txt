cmake_minimum_required(VERSION 3.10)
project(BackendTest)

# For drogon
set(BUILD_EXAMPLES OFF)

set(
    BACKEND_SOURCE_FILES

    src/Controllers/TestController.cpp
    src/Controllers/JsonController.cpp
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    BackendTest

    main.cpp

    ${BACKEND_SOURCE_FILES}
)

target_link_libraries(BackendTest drogon)

target_include_directories(BackendTest PUBLIC include/)

add_subdirectory(libraries/drogon)
