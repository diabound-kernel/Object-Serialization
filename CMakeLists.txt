cmake_minimum_required(VERSION 3.18)
project(Object_Serialization)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.2
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
    yaml-cpp
    GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
    GIT_TAG yaml-cpp-0.6.3
)
FetchContent_MakeAvailable(yaml-cpp)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG master
)
FetchContent_MakeAvailable(fmt)

add_executable(Object_Serialization main.cpp introspection/)
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json -lyaml-cpp fmt::fmt)