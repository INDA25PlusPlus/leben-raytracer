//
// Created by Leonard on 2026-01-15.
//

#include "scene/Sphere.hpp"

#include <cmath>
#include <limits>


Sphere::Sphere(Vec3 pos, number_t radius, Material const &material) :
    SceneObject(material), pos(pos), radius(radius) {}

bool Sphere::ray_cast(Ray3 const &ray, std::optional<HitInfo> &hit) const {
    // assumes ray dir is unit length, and ray origin is not inside sphere
    //
    // given ray origin (f), direction (d), sphere center (c), radius (r):
    // we solve the following for non-negative t:
    // |(f + td) - c|² = r²
    //
    // let Δ = f - c
    // |Δ + td|² = r² ⇔
    // (Δ + td)·(Δ + td) = r² ⇔
    // (d·d)t² + (2Δ·d)t + Δ·Δ - r² = 0 ⇔
    // t² + (2Δ·d)t + Δ·Δ - r² = 0 (assume |d| = 1)
    //
    // let p_half = Δ·d
    // let q = Δ·Δ - r²
    // let D = p_half² - q = (Δ·d)² - Δ·Δ + r²
    // t₁ = -p_half - √D
    // t₂ = -p_half + √D
    //
    // we have 4 cases:
    // (1) D  < 0       (no intersection)
    // (2) 0  ≤ t₁ < t₂ (intersection with t = t₁, f is outside sphere)
    // (3) t₁ < 0  ≤ t₂ (intersection with t = t₂, f is inside sphere)
    // (4) t₁ < t₂ < 0  (no intersection)
    //
    // algorithm:
    // - check D < 0
    // - if f is outside sphere: check 0 ≤ t₁
    //     ⇔ 0 ≥ p_half + √D
    //     ⇔ -p_half ≥ √D
    //     ⇔ p_half < 0 AND p_half² ≥ D
    //     ⇔ p_half < 0 AND q ≥ 0
    //     ⇔ p_half < 0 (because |Δ| ≥ r ⇒ q ≥ 0)
    //   - return t₁
    // - if f is inside sphere: check 0 ≤ t₂
    //     ⇔ 0 ≤ -p_half + √D
    //     ⇔ p_half ≤ √D
    //     ⇔ p_half < 0 OR p_half² ≤ D
    //     ⇔ p_half < 0 OR q ≤ 0
    //   - which is true because |Δ| ≤ r ⇒ q ≤ 0
    //   - return t₂

    Vec3 Delta = ray.from - pos;
    number_t p_half = Vec3::dot(Delta, ray.dir);
    number_t q = Delta.sq() - radius * radius;
    number_t D = p_half * p_half - q;

    if (D < 0 || p_half > 0)
        return false;

    number_t min_dist = hit ? hit->distance : std::numeric_limits<number_t>::max();

    //   min_dist < -p_half - √D
    // ⇔       √D < -(p_half + min_dist)
    // ⇔        D < (p_half + min_dist)² AND p_half + min_dist < 0
    number_t pd = p_half + min_dist;
    if (D < pd * pd && pd < 0)
        return false;

    number_t t1 = -p_half - std::sqrt(D);

    Vec3 hit_pos = ray.from + ray.dir * t1;
    hit.emplace(
        t1,
        hit_pos,
        (hit_pos - pos).norm(),
        material
    );
    return true;
}
