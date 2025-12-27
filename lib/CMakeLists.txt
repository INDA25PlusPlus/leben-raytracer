file(GLOB_RECURSE COMMON_SOURCES ${PROJECT_SOURCE_DIR}/lib/common/*)
file(GLOB_RECURSE CPU_ONLY_SOURCES ${PROJECT_SOURCE_DIR}/lib/cpu_only/*)
file(GLOB_RECURSE CUDA_SOURCES ${PROJECT_SOURCE_DIR}/lib/cuda/*)

add_library(leben_raytracer_lib_cpu_only ${COMMON_SOURCES} ${CPU_ONLY_SOURCES})
target_include_directories(leben_raytracer_lib_cpu_only PUBLIC ${PROJECT_SOURCE_DIR}/lib/include)

if(ENABLE_CUDA)
    enable_language(CUDA)

    include(CheckLanguage)
    # Sets CMAKE_CUDA_COMPILER if CUDA language is available
    check_language(CUDA)

    if(CMAKE_CUDA_COMPILER)
        set(CUDA_SUCCESSFULLY_ENABLED ON)

        add_library(leben_raytracer_lib_cuda ${COMMON_SOURCES} ${CUDA_SOURCES})
        target_include_directories(leben_raytracer_lib_cuda PUBLIC ${PROJECT_SOURCE_DIR}/lib/include)
        set_target_properties(leben_raytracer_lib_cuda PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
    else()
        # Expect CUDA language to be available if ENABLE_CUDA is set
        set(CUDA_SUCCESSFULLY_ENABLED OFF)
        message(WARNING "CUDA toolkit not available, falling back to CPU-only.")
    endif()
else()
    set(CUDA_SUCCESSFULLY_ENABLED OFF)
endif()
