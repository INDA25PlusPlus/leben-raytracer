//
// Created by Leonard on 2025-12-27.
//

#pragma once
#include <string>

#include "config.hpp"


struct Vec2 {
    static const Vec2 ZERO, ONE, X, Y;

    number_t x, y;

    Vec2(const Vec2 &v) = default;
    Vec2(number_t x, number_t y);
    explicit Vec2(number_t xy);

    Vec2 operator+(const Vec2 &w) const;
    Vec2 operator+(number_t w) const;

    Vec2 operator-(const Vec2 &w) const;
    Vec2 operator-(number_t w) const;

    Vec2 operator*(const Vec2 &w) const;
    Vec2 operator*(number_t w) const;

    Vec2 operator/(const Vec2 &w) const;
    Vec2 operator/(number_t w) const;

    Vec2 operator-() const;

    number_t sq() const;
    number_t magn() const;
    Vec2 norm() const;

    std::string debug_string() const;

    static number_t dot(const Vec2 &v, const Vec2 &w);

    static Vec2 min(const Vec2 &v, const Vec2 &w);
    static Vec2 max(const Vec2 &v, const Vec2 &w);
};
