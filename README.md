# Gravity Simulator C++

# Build Instruction
`Requrements:` Have a package manager: vcpkg installed and configured 
## Use Cmake to generate build files 
### MSVC
- Open terminal in the project root directory
- use command `cmake --preset windows64-VS-Debug`

### Unix Makefiles
- Open terminal in the project root directory
- use command `cmake --preset windows64-GCC-Debug`

## Build
### MSVC
- `cd ./build/windows64-VS-Debug/`
- `msbuild GravitySim.sln`

### Makefiles
- `cd ./build/windows64-GCC-Debug/`
- `make`


Thank you for trying out this project ❤️