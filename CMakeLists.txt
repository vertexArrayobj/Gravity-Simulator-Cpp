cmake_minimum_required(VERSION 3.10.0)

project(GravitySim VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
endif()

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(Stb REQUIRED)

file(GLOB_RECURSE MY_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${MY_SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE GLEW_STATIC)
target_compile_definitions(${PROJECT_NAME} PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/res/")

target_include_directories(${PROJECT_NAME} PRIVATE ${Stb_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE 
    glfw
    opengl32
    GLEW::GLEW
    imgui::imgui
    glm::glm
)