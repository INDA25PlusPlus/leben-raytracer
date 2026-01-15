//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include "SceneObject.hpp"

class Sphere final : public SceneObject {
    Vec3 const pos;
    number_t const radius;

public:
    Sphere(Vec3 pos, number_t radius, Material const &material);

    bool ray_cast(Ray3 const &ray, std::optional<HitInfo> &hit) const override;
};
