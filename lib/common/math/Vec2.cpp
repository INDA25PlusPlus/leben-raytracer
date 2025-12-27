//
// Created by Leonard on 2025-12-27.
//

#include "math/Vec2.hpp"

#include <cmath>
#include <format>

const Vec2 Vec2::ZERO = {0, 0};
const Vec2 Vec2::ONE = {1, 1};
const Vec2 Vec2::X = {1, 0};
const Vec2 Vec2::Y = {0, 1};

Vec2::Vec2(number_t x, number_t y) : x(x), y(y) {}

Vec2::Vec2(number_t xy) : x(xy), y(xy) {}

Vec2 Vec2::operator+(const Vec2 &w) const {
    return {x + w.x, y + w.y};
}

Vec2 Vec2::operator+(number_t w) const {
    return {x + w, y + w};
}

Vec2 Vec2::operator-(const Vec2 &w) const {
    return {x - w.x, y - w.y};
}

Vec2 Vec2::operator-(number_t w) const {
    return {x - w, y - w};
}

Vec2 Vec2::operator*(const Vec2 &w) const {
    return {x * w.x, y * w.y};
}

Vec2 Vec2::operator*(number_t w) const {
    return {x * w, y * w};
}

Vec2 Vec2::operator/(const Vec2 &w) const {
    return {x / w.x, y / w.y};
}


Vec2 Vec2::operator/(const number_t w) const {
    return {x / w, y / w};
}

Vec2 Vec2::operator-() const {
    return {-x, -y};
}

number_t Vec2::sq() const {
    return x*x + y*y;
}

number_t Vec2::magn() const {
    return std::sqrt(x*x + y*y);
}

Vec2 Vec2::norm() const {
    return *this / magn();
}

std::string Vec2::debug_string() const {
    return std::format("({:12.4f}, {:12.4f})", x, y);
}

number_t Vec2::dot(const Vec2 &v, const Vec2 &w) {
    return v.x * w.x + v.y * w.y;
}

Vec2 Vec2::min(const Vec2 &v, const Vec2 &w) {
    return {std::min(v.x, w.x), std::min(v.y, w.y)};
}

Vec2 Vec2::max(const Vec2 &v, const Vec2 &w) {
    return {std::max(v.x, w.x), std::max(v.y, w.y)};
}
