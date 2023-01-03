cmake_minimum_required(VERSION 3.18)
project(Object_Serialization)

set(CMAKE_CXX_STANDARD 20)

include_directories(third-party/fmt/include/)
include_directories(third-party/json/single_include/)
include_directories(third-party/yaml-cpp/include/)

find_package(fmt)
add_executable(Object_Serialization main.cpp introspection/macros.hpp introspection/metadata.hpp introspection/json.hpp introspection/yaml.hpp)
target_link_libraries(${PROJECT_NAME} fmt::fmt -lyaml-cpp)