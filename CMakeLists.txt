cmake_minimum_required(VERSION 3.10)
project(BackendTest)

# For drogon
set(BUILD_EXAMPLES OFF)

set(
    BACKEND_SOURCE_FILES

    src/TestController.cpp
)

add_executable(
    BackendTest

    main.cpp

    ${BACKEND_SOURCE_FILES}
)

target_link_libraries(BackendTest drogon)

target_include_directories(BackendTest PUBLIC include/)

add_subdirectory(libraries/drogon)
