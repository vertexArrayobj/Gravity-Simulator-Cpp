# Gravity Simulator C++

A C++ physics simulation that models gravitational interactions between celestial bodies.

![Project Screenshot](./screenshots/screenshot.png) <!-- Add a screenshot if available -->

## Features

- N-body gravitational simulation
- Real-time visualization
- Configurable physical parameters
- [Add other key features]

## Prerequisites

- [vcpkg](https://vcpkg.io) package manager installed and configured [make sure your environment variable VCPKG_ROOT is set]
- CMake 3.15+
- C++20 compatible compiler

## Installation & Build

### 1. Generate Build Files

#### For Visual Studio (MSVC)

```bash
# Debug configuration
cmake --preset windows64-VS-Debug

# Release configuration
cmake --preset windows64-VS-Release
```

#### For GCC/Ninja

```bash
cmake --preset windows64-GCC-Debug
```

### 2. Compile the Project

#### MSVC Builds

```bash
# Debug build
cmake --build build/windows64-VS-Debug

# Release build
make --build build/windows64-VS-Release --config Release
```

#### GCC/Ninja Builds

```bash
cmake --build build/windows64-GCC-Debug
```

# Contributing

Pull requests are welcome. Please open an issue first to discuss proposed changes.

# License

[LICENSE](./LICENSE.txt)

Thank you for using Gravity Simulator! ❤️
