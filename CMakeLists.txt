cmake_minimum_required(VERSION 4.0)
project(MyEngine2D)

set(CMAKE_CXX_STANDARD 20)

#Find a SDL3
set(SDL2_DIR "${CMAKE_SOURCE_DIR}/packages/SDL3")
include_directories(${SDL2_DIR}/include)
link_directories(${SDL2_DIR}/lib)

#Find a SDL3_image
set(SDL3_IMAGE_DIR "${CMAKE_SOURCE_DIR}/packages/SD3_image")
include_directories(${SDL3_IMAGE_DIR}/include)
link_directories(${SDL3_IMAGE_DIR}/lib)

#Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

#Find Glew
set(GLEW_DIR "${CMAKE_SOURCE_DIR}/packages/GLEW")
include_directories(${GLEW_DIR}/include)
link_directories(${GLEW_DIR}/lib)

#Set include folder
include_directories(${CMAKE_SOURCE_DIR}/include)

#Add a executable
add_executable(MyEngine2D
        main.cpp
        src/Core/Time.cpp
        src/Core/Window.cpp
        src/ECS/Component.cpp
        src/ECS/Entity.cpp
        src/ECS/System.cpp
        src/Renderer/Renderer.cpp
        src/Renderer/Texture.cpp
        src/Core/Application.cpp
)

#Makes a link to libraries
target_link_libraries(MyEngine2D
        mingw32
        SDL2
        SDL2_image
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES}
        glew32
)