#ifndef YAML_HPP
#define YAML_HPP

#include "yaml-cpp/yaml.h"

#include "metadata.hpp"

namespace YAML
{
    template<typename Object>
    struct convert
    {
        static Node encode(const Object& obj)
        {
            Node node;
            to_yaml(node, obj);
            return node;
        }

        static bool decode(const Node& node, Object& obj)
        {
            from_yaml(node, obj);
            return true;
        }
    };

    template<typename Object>
    void to_yaml(Node& node, const Object& obj)
    {
        metadata::forEachField(obj, [&](auto field)
        {
            node[std::get<0>(field)] = std::get<2>(field)(obj);
        });
    }

    template<typename Field>
    auto get_to(const Node& node, Field& field)
    {
        field = node.template as<Field>();
    }

    template<typename Object>
    void from_yaml(const Node& node, Object& obj)
    {
        metadata::forEachField(obj, [&](auto field)
        {
            get_to(node[std::get<0>(field)], std::get<1>(field));
        });
    }
} // namespace YAML

#endif // YAML_HPP