cmake_minimum_required(VERSION 3.30.5)

# options
option(ENABLE_CUDA_FEATURES "Enable GPU-side rendering")
if (ENABLE_CUDA_FEATURES)
    add_compile_definitions(ENABLE_CUDA_FEATURES=true)
else()
    add_compile_definitions(ENABLE_CUDA_FEATURES=false)
endif()

# languages
list(APPEND languages CXX)
set(CMAKE_CXX_STANDARD 20)
if(ENABLE_CUDA_FEATURES)
    list(APPEND languages CUDA)
    set(CMAKE_CUDA_STANDARD 20)
endif()

project(leben_raytracer LANGUAGES ${languages})

# sources
file(GLOB_RECURSE common_sources src/common/*)
file(GLOB_RECURSE host_sources src/host/*)
file(GLOB_RECURSE cuda_sources src/cuda/*)

# targets
if(ENABLE_CUDA_FEATURES)
    add_executable(leben_raytracer_cuda src/main.cpp ${common_sources} ${cuda_sources})
    add_executable(leben_raytracer_cuda_test src/test.cpp ${common_sources} ${cuda_sources})
    set_target_properties(leben_raytracer_cuda PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
else()
    add_executable(leben_raytracer_host src/main.cpp ${common_sources} ${host_sources})
    add_executable(leben_raytracer_host_test src/test.cpp ${common_sources} ${host_sources})
endif()
