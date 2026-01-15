//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include "SceneObject.hpp"

class Plane final : public SceneObject {
    Vec3 const pos;
    number_t const dist;

public:
    Plane(Vec3 pos, number_t dist, Material const &material);

    bool ray_cast(Ray3 const &ray, double &min_dist, Vec3 &pos, Vec3 &normal) const override;
};
