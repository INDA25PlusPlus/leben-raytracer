file(GLOB_RECURSE COMMON_SOURCES common/*)
file(GLOB_RECURSE CPU_ONLY_SOURCES cpu_only/*)
file(GLOB_RECURSE CUDA_SOURCES cuda/*)

add_library(leben_raytracer_lib_cpu_only ${COMMON_SOURCES} ${CPU_ONLY_SOURCES})
target_include_directories(leben_raytracer_lib_cpu_only PUBLIC ${PROJECT_SOURCE_DIR}/lib/include)

if(ENABLE_CUDA)
    enable_language(CUDA)

    include(CheckLanguage)
    check_language(CUDA)

    if(CMAKE_CUDA_COMPILER)
        set(CUDA_SUCCESSFULLY_ENABLED ON)

        add_library(leben_raytracer_lib_cuda ${COMMON_SOURCES} ${CUDA_SOURCES})
        target_include_directories(leben_raytracer_lib_cuda PUBLIC ${PROJECT_SOURCE_DIR}/lib/include)
        set_target_properties(leben_raytracer_lib_cuda PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
    else()
        set(CUDA_SUCCESSFULLY_ENABLED OFF)
        message(WARNING "CUDA toolkit not available, falling back to cpu-only.")
    endif()
else()
    set(CUDA_SUCCESSFULLY_ENABLED OFF)
endif()
