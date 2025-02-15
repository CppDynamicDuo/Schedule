cmake_minimum_required(VERSION 3.10)
project(BackendTest)

# For drogon
set(BUILD_EXAMPLES OFF)
set(BUILD_TESTING OFF)

set(OUTPUT_DIR ${CMAKE_BINARY_DIR})

set(
    BACKEND_SOURCE_FILES

    src/Controllers/TestController.cpp
    src/Controllers/JsonController.cpp
    src/DatabaseManager.cpp
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    BackendTest

    main.cpp

    ${BACKEND_SOURCE_FILES}
)

target_link_libraries(BackendTest drogon)

include_directories(${CMAKE_SOURCE_DIR}/include/)

target_include_directories(BackendTest PUBLIC ${CMAKE_SOURCE_DIR}/include/)

add_subdirectory(libraries/drogon)
