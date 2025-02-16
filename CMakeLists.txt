cmake_minimum_required(VERSION 3.10)
project(BackendTest)

# For drogon
set(BUILD_EXAMPLES OFF)
set(BUILD_TESTING OFF)

set(OUTPUT_DIR ${CMAKE_BINARY_DIR})

file(GLOB BACKEND_SOURCES "src/*.cpp" "src/*/*.cpp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    BackendTest

    ${BACKEND_SOURCES}
)

target_link_libraries(BackendTest drogon)

include_directories(${CMAKE_SOURCE_DIR}/include/)

target_include_directories(BackendTest PUBLIC ${CMAKE_SOURCE_DIR}/include/)

add_subdirectory(libraries/drogon)
