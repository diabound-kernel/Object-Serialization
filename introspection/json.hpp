#ifndef JSON_HPP
#define JSON_HPP

#include "metadata.hpp"

#include "nlohmann/json.hpp"

template<typename Object>
void to_json(nlohmann::json &j, const Object &obj)
{
    metadata::forEachField(obj, [&](auto field) {
        j[std::get<metadata::Field::Name>(field)] =
            std::get<metadata::Field::Invoke>(field)(obj);
    });
}

template<typename Object>
void from_json(const nlohmann::json &j, Object &obj)
{
    metadata::forEachField(obj, [&](auto field) {
        j.at(std::get<metadata::Field::Name>(field))
            .get_to(std::get<metadata::Field::Ref>(field));
    });
}

#endif  // JSON_HPP