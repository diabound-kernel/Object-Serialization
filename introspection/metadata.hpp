#ifndef METADATA_HPP
#define METADATA_HPP

#include "macros.hpp"

#include <tuple>
#include <functional>

#define INVOKE_FIELD(FIELD) \
    [](auto obj) { return std::forward<decltype(obj.FIELD)>(obj.FIELD); }

#define FIELD_PAIR(FIELD)                            \
    , std::make_tuple(                               \
        #FIELD, std::ref(FIELD), INVOKE_FIELD(FIELD) \
    )

#define FIELD_PAIRS(...) FOR_EACH(FIELD_PAIR, __VA_ARGS__)

#define GEN_METADATA(FIRST, ...)                            \
    constexpr auto getFields()                              \
    {                                                       \
        return std::make_tuple(                             \
            std::make_tuple(#FIRST, std::ref(FIRST),        \
            INVOKE_FIELD(FIRST)) FIELD_PAIRS(__VA_ARGS__)); \
    }                                                       \
                                                            \
    constexpr auto getFields() const                        \
    {                                                       \
        return std::make_tuple(                             \
            std::make_tuple(#FIRST, std::ref(FIRST),        \
            INVOKE_FIELD(FIRST)) FIELD_PAIRS(__VA_ARGS__)); \
    }

namespace metadata
{
    template<typename Object>
    concept CanGetFields = requires(Object& obj) { obj.getFields(); };

    template<CanGetFields Object, typename Func>
    void forEachField(Object& obj, Func&& func) {
        std::apply([&func](auto ...fields)
        {
            (func(fields), ...);
        }, obj.getFields());
    }
} // namespace metadata

#endif // METADATA_HPP
