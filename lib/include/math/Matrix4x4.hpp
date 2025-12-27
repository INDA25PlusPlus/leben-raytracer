//
// Created by Leonard on 2025-12-27.
//

#pragma once
#include "Matrix3x3.hpp"
#include "Ray3.hpp"
#include "config.hpp"


struct Matrix4x4 {
    static const Matrix4x4 I;

    number_t
        e11, e12, e13, e14,
        e21, e22, e23, e24,
        e31, e32, e33, e34,
        e41, e42, e43, e44;

    Matrix4x4(const Matrix4x4 &m) = default;

    Matrix4x4(
        number_t e11, number_t e12, number_t e13, number_t e14,
        number_t e21, number_t e22, number_t e23, number_t e24,
        number_t e31, number_t e32, number_t e33, number_t e34,
        number_t e41, number_t e42, number_t e43, number_t e44);

    /**
     * Instantiate an affine transformation matrix with matrix transformation
     * @c m and offset @c v.
     * See https://en.wikipedia.org/wiki/Affine_transformation#Augmented_matrix
     */
    Matrix4x4(const Matrix3x3 &m, const Vec3 &v);

    Matrix4x4 operator+(const Matrix4x4 &m) const;
    Matrix4x4 operator-(const Matrix4x4 &m) const;

    Matrix4x4 operator-() const;
    Matrix4x4 operator*(number_t d) const;

    Matrix4x4 operator*(const Matrix4x4 &m) const;

    /**
     * Apply the affine transformation represented by this matrix to a vector.
     * @return The transformed vector.
     */
    Vec3 apply(const Vec3 &v) const;

    /**
     * Apply the affine transformation represented by this matrix to a ray.
     * @return The transformed ray.
     */
    Ray3 apply(const Ray3 &r) const;

    Matrix4x4 transpose() const;

    std::string debug_string() const;

private:
    Vec3 apply_only_matrix_part(const Vec3 &v) const;
};
