#include <cstdint>
#include <string>

#include "fmt/ostream.h"

#include "introspection/json.hpp"
#include "introspection/yaml.hpp"

struct Socket
{
    std::string address;
    std::uint64_t port;
    std::string state;

    GEN_METADATA(address, port, state);
};

int main(int argc, const char *argv[])
{
    auto socket = YAML::LoadFile("../socket.yaml").as<Socket>();

    fmt::print("{}\n", ::nlohmann::json(socket).dump());

    return 0;
}