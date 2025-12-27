# leben-raytracer

Me when I trace the ray 😳

## Usage

Build using CMake or use the utility scripts at `scripts/`. Configure CUDA features using the `ENABLE_CUDA` flag.

### Configure

Compile with CUDA features: `scripts/conf_cmake.sh cuda`
(requires CUDA toolkit to be installed; target can only be executed on systems with CUDA GPU:s)

Use CPU-only substitutes: `scripts/conf_cmake.sh cpu_only`
(can be built and executed on any system)

### Build and run

Build: `scripts/build.sh`

Build and run: `scripts/run.sh`

Build and run tests: `scripts/test.sh`
