cmake_minimum_required(VERSION 3.30.5)
set(CMAKE_CXX_STANDARD 20)

project(leben_raytracer LANGUAGES CXX)

add_subdirectory(lib)

file(GLOB_RECURSE EXE_SOURCES)
add_executable(leben_raytracer src/main.cpp ${EXE_SOURCES})
add_executable(leben_raytracer_test src/test.cpp ${EXE_SOURCES})

target_link_libraries(leben_raytracer PRIVATE leben_raytracer_lib)
target_link_libraries(leben_raytracer_test PRIVATE leben_raytracer_lib)
