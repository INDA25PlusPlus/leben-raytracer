//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include <cstdint>

#include "math/Vec3.hpp"

using rgba_t = uint32_t;

using Color3 = Vec3;

inline rgba_t wrap(Color3 const &rgb, number_t ref) {
    auto r = static_cast<uint8_t>(rgb.x / ref);
    auto g = static_cast<uint8_t>(rgb.y / ref);
    auto b = static_cast<uint8_t>(rgb.z / ref);
    return 0x000000ff
        | r << 24
        | g << 16
        | b << 8;
}

inline Color3 unwrap(rgba_t rgba, number_t ref) {
    auto r = rgba >> 24 & 0xff;
    auto g = rgba >> 16 & 0xff;
    auto b = rgba >> 8 & 0xff;
    auto a = rgba & 0xff;
    auto scale = static_cast<number_t>(a) * ref;
    return {
        static_cast<number_t>(r) * scale,
        static_cast<number_t>(g) * scale,
        static_cast<number_t>(b) * scale,
    };
}
