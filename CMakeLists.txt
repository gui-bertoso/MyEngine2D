cmake_minimum_required(VERSION 4.0)
project(MyEngine2D)

set(CMAKE_CXX_STANDARD 20)

#Find a SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#Find a SDL2_image
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

#Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

#Find Glew
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

#Set include folder
include_directories(${CMAKE_SOURCE_DIR}/include)

#Add a executable
add_executable(MyEngine2D main.cpp
        src/Core/Time.cpp
        src/Core/Window.cpp
        src/ECS/Component.cpp
        src/ECS/Entity.cpp
        src/ECS/System.cpp
        src/Renderer/Renderer.cpp
        src/Renderer/Texture.cpp
        src/Core/Application.cpp)

#Makes a link to libraries
target_link_libraries(MyEngine2D
        ${SDL2_LIBRARIES}
        /usr/lib64/libSDL2_image.so
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES}
)