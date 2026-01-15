//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include <cstdint>

#include "math/Vec3.hpp"

using rgba_t = uint32_t;

using Color3 = Vec3;

inline rgba_t wrap(Color3 const &rgb, number_t ref) {
    auto r = static_cast<uint8_t>(255.0 * rgb.x / ref);
    auto g = static_cast<uint8_t>(255.0 * rgb.y / ref);
    auto b = static_cast<uint8_t>(255.0 * rgb.z / ref);
    return 0xff000000
        | r
        | g << 8
        | b << 16;
}

inline Color3 unwrap(rgba_t rgba, number_t ref) {
    auto r = rgba & 0xff;
    auto g = rgba >> 8 & 0xff;
    auto b = rgba >> 16 & 0xff;
    auto a = rgba >> 24 & 0xff;
    number_t scale = static_cast<number_t>(a) * ref / 255.0;
    return {
        static_cast<number_t>(r) * scale,
        static_cast<number_t>(g) * scale,
        static_cast<number_t>(b) * scale,
    };
}
