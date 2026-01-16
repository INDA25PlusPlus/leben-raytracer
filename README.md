# leben-raytracer

Me when I trace the ray 😳

## Usage

To create a material, specify in order:
- Emissive color: The color of light that the material gives off
- Emissivity: The amount of light that the material gives off
- Diffuse color: Color of diffusively reflected light
- Specular color: Color of specularly reflected light
- Reflectivity: The ratio of total reflected light to incoming light
- Roughness: The ratio of diffuse reflection to total reflection

Example:
```cpp
Material matte_mat {
    {.0, .0, .0}, 0.,
    {1., 1., 1.}, {0., 0., 0.}, .9, 1.};
```

To add objects to the scene:

```cpp
scene.add_object(std::make_unique<Plane>(Vec3::Z, matte_mat));
```

For planes, the `pos` field indicates the point on the plane on which the origin lies orthogonal to the plane.

Resulting images are automatically saved to `out/`.

## Configuration

See `lib/config.hpp` for configuration options. Specify them as define flags in the compilation step.

| Flag             | Type     | Description                      | Default value |
|------------------|----------|----------------------------------|---------------|
| RES_X            | integer  | output image resolution, x       | 1920          |
| RES_Y            | integer  | output image resolution, y       | 1080          |
| SAMPLE_COUNT     | integer  | samples per pixel                | 20            |
| MIN_CONTRIBUTION | floating | light ray contribution threshold | 0.01          |
| MAX_DEPTH        | integer  | reflection recursion limit       | 10            |
| PRINT_PROGRESS   | bool     | print rendering progress?        | true          |
| DOUBLE_PRECISION | bool     | use double instead of float?     | true          |

## Build and run

Build using CMake or use the utility scripts at `scripts/`.

Configure CMake: `scripts/conf_cmake.sh`

Build: `scripts/build.sh`

Build and run: `scripts/run.sh`

Build and run tests: `scripts/test.sh`
