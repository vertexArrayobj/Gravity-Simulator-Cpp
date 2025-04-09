cmake_minimum_required(VERSION 3.10.0)

project(GravitySim VERSION 0.1.0 LANGUAGES C CXX)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

# Gather all source files
file(GLOB_RECURSE MY_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Define the executable
add_executable(GravitySim ${MY_SOURCES})

# Define GLEW_STATIC for the compiler
target_compile_definitions(GravitySim PRIVATE GLEW_STATIC)

target_link_libraries(GravitySim PRIVATE 
    glfw
    opengl32
    GLEW::GLEW
)
