//
// Created by Leonard on 2025-12-26.
//

#include <iostream>

#include "math/Vec2.hpp"
#include "render/RenderBuffer.hpp"
#include "scene/Plane.hpp"
#include "scene/Scene.hpp"
#include "scene/Sphere.hpp"

int main() {
    Material light_mat {
        {.8, .8, .8}, .4,
        {0., 0., 0.}, {1., 1., 1.}, .8, 0.};
    Material matte_mat {
        {.0, .0, .0}, 0.,
        {1., 1., 1.}, {0., 0., 0.}, .9, 1.};
    Material red_mat {
        {0., 0., 0.}, 0.,
        {1., 0., 0.}, {1., 0., 0.}, .9, .8};
    Material yellow_mat {
            {0., 0., 0.}, 0.,
            {1., 1., 0.}, {1., 1., 0.}, .9, .8};

    Scene scene;
    scene.add_object(std::make_unique<Plane>(Vec3::Z * 100, light_mat));
    scene.add_object(std::make_unique<Plane>(Vec3::Z, matte_mat));
    scene.add_object(std::make_unique<Plane>(Vec3{-2, 0, 1}, matte_mat));
    scene.add_object(std::make_unique<Sphere>(Vec3{0, 2, 2}, 1, red_mat));
    scene.add_object(std::make_unique<Sphere>(Vec3{0, -2, 2}, 1, yellow_mat));

    Matrix4x4 proj_matrix {
        Matrix3x3::from_forward_down_vecs(
            Vec3::X,
            -Vec3::Z
        ),
        {-5, 0, 2}
    };

    std::random_device device{};

    RenderBuffer buffer;
    buffer.render(scene, proj_matrix, 0.4 * std::numbers::pi, device);

    std::string output_path = buffer.write_png("./out/out.png");
    std::cout << output_path << std::endl;
    return 0;
}
