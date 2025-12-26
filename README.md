# leben-raytracer

Me when I trace the ray 😳

## Usage

Build using CMake or use the utility scripts at `scripts/`:

### Host (CPU only)

Generate CMake context: `scripts/cmake_gen.sh`

Build and run: `scripts/run.sh`
Build and run tests: `scripts/run.sh host_test`

### CUDA (GPU acceleration)

Generate CMake context: `scripts/cmake_gen.sh cuda`

Build and run: `scripts/run.sh cuda`
Build and run tests: `scripts/run.sh cuda_test`
