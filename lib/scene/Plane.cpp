//
// Created by Leonard on 2026-01-15.
//

#include "scene/Plane.hpp"

#include <limits>


Plane::Plane(Vec3 pos, Material const &material) :
    SceneObject(material), pos(pos) {}

bool Plane::ray_cast(Ray3 const &ray, std::optional<HitInfo> &hit) const {
    // assumes ray dir is unit length
    //
    // given ray origin (f), direction (d), point on plane with origin in normal direction (p):
    // we solve the following for non-negative t:
    // (f + td - p) * p = 0
    //
    // f * p + td * p - p^2 = 0
    // t = (p^2 - f * p)/(d * p)

    // denominator == 0 is ok because -inf => no intersection, inf => too far
    number_t t = Vec3::dot(pos, pos) - Vec3::dot(ray.from, pos) / Vec3::dot(ray.dir, pos);

    if (t < 0)
        return false;

    number_t min_dist = hit ? hit->distance : std::numeric_limits<number_t>::max();
    if (t > min_dist)
        return false;

    Vec3 hit_pos = ray.from + ray.dir * t;
    Vec3 hit_normal = pos.norm() * (Vec3::dot(pos, ray.dir) > 0 ? -1 : 1);
    hit.emplace(
        t,
        hit_pos,
        hit_normal,
        material
    );
    return true;
}
