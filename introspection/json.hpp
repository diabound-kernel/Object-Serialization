#ifndef JSON_HPP
#define JSON_HPP

#include "nlohmann/json.hpp"

#include "metadata.hpp"

template<typename Object>
void to_json(nlohmann::json& j, const Object& obj)
{
    metadata::forEachField(obj, [&](auto field)
    {
        j[std::get<0>(field)] = std::get<2>(field)(obj);
    });
}

template<typename Object>
void from_json(const nlohmann::json& j, Object& obj)
{
    metadata::forEachField(obj, [&](auto field)
    {
        j.at(std::get<0>(field)).get_to(std::get<1>(field));
    });
}

#endif // JSON_HPP