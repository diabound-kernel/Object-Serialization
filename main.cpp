#define FMT_HEADER_ONLY
#include "fmt/ostream.h"

#include "introspection/json.hpp"
#include "introspection/yaml.hpp"

#include <string>

struct Socket
{
    std::string address;
    int port;
    std::string state;

    GEN_METADATA(address, port, state);
};

int main()
{
    auto socket = YAML::LoadFile("../socket.yaml").as<Socket>();

    fmt::print("{}\n", nlohmann::json(socket).dump());

    return 0;
}