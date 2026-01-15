//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include "SceneObject.hpp"

class Plane final : public SceneObject {
    Vec3 const pos;

public:
    Plane(Vec3 pos, Material const &material);

    bool ray_cast(Ray3 const &ray, std::optional<HitInfo> &hit) const override;
};
