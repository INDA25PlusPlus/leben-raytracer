cmake_minimum_required(VERSION 3.30.5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CUDA_STANDARD 20)

project(leben_raytracer LANGUAGES C CXX)
option(ENABLE_CUDA "Enable GPU-side rendering using CUDA")

add_subdirectory(lib)

file(GLOB_RECURSE EXE_SOURCES src/*)

add_executable(leben_raytracer main.cpp ${EXE_SOURCES})
add_executable(leben_raytracer_test test.cpp ${EXE_SOURCES})

if(CUDA_SUCCESSFULLY_ENABLED)
    target_link_libraries(leben_raytracer PRIVATE leben_raytracer_lib_cuda)
    target_link_libraries(leben_raytracer_test PRIVATE leben_raytracer_lib_cuda)
else()
    target_link_libraries(leben_raytracer PRIVATE leben_raytracer_lib_cpu_only)
    target_link_libraries(leben_raytracer_test PRIVATE leben_raytracer_lib_cpu_only)
endif()
