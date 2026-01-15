add_library(leben_raytracer_lib
        math/Matrix3x3.cpp
        math/Matrix4x4.cpp
        math/Ray3.cpp
        math/Vec2.cpp
        math/Vec3.cpp
        scene/SceneObject.cpp
        scene/Sphere.cpp
        scene/Plane.cpp
        render/RenderBuffer.cpp
)
target_include_directories(leben_raytracer_lib PUBLIC ${PROJECT_SOURCE_DIR}/lib/include)
