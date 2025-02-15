cmake_minimum_required(VERSION 3.10)
project(BackendTest)

# For drogon
set(BUILD_EXAMPLES OFF)
set(BUILD_TESTING OFF)

set(OUTPUT_DIR ${CMAKE_BINARY_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR} CACHE STRING "" FORCE)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR} CACHE STRING "" FORCE)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR} CACHE STRING "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE STRING "" FORCE)

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

add_subdirectory(libraries/jsoncpp)

set(
    JSONCPP_INCLUDE_DIRS

    ${CMAKE_SOURCE_DIR}/libraries/jsoncpp/include
)

set(
    JSONCPP_LIBRARIES

    .
    #${CMAKE_BINARY_DIR}/libjsoncpp.a
)

add_subdirectory(libraries/drogon)

message("${JSONCPP_INCLUDE_DIRS}")
message("${JSONCPP_LIBRARIES}")
