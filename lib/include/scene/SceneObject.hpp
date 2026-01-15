//
// Created by Leonard on 2026-01-15.
//

#pragma once
#include <optional>

#include "math/Ray3.hpp"
#include "render/HitInfo.hpp"
#include "render/Material.hpp"

class SceneObject {
public:
    Material const &material;

    explicit SceneObject(Material const &material);

    virtual ~SceneObject() = default;

    virtual bool ray_cast(Ray3 const &ray, std::optional<HitInfo> &hit) const = 0;
};
