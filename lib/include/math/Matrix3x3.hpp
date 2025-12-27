//
// Created by Leonard on 2025-12-27.
//

#pragma once
#include <string>

#include "Vec3.hpp"
#include "config.hpp"


struct Matrix3x3 {
    static const Matrix3x3 I;

    number_t
        e11, e12, e13,
        e21, e22, e23,
        e31, e32, e33;

    Matrix3x3(const Matrix3x3 &m) = default;

    Matrix3x3(
        number_t e11, number_t e12, number_t e13,
        number_t e21, number_t e22, number_t e23,
        number_t e31, number_t e32, number_t e33);

    Matrix3x3(const Vec3 &v1, const Vec3 &v2, const Vec3 &v3);

    Matrix3x3 operator+(const Matrix3x3 &m) const;
    Matrix3x3 operator-(const Matrix3x3 &m) const;

    Matrix3x3 operator-() const;
    Matrix3x3 operator*(number_t d) const;

    Matrix3x3 operator*(const Matrix3x3 &m) const;
    Vec3 operator*(const Vec3 &v) const;

    Matrix3x3 transpose() const;
    number_t det() const;

    std::string debug_string() const;

    /**
     * @return The change-of-basis matrix from the standard basis to the basis
     * where x -> right, y -> down, z -> forward.
     */
    static Matrix3x3 from_forward_down_vecs(
        const Vec3 &forward, const Vec3 &down);

    /**
     * @return The determinant of the matrix formed by the column vectors @c v1,
     * @c v2, @c v3.
     */
    static number_t det(const Vec3 &v1, const Vec3 &v2, const Vec3 &v3);
};
