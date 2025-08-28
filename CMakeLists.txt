cmake_minimum_required(VERSION 4.0)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

#Find a SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#Find OpenGL
find_package(OpenGl REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

#Find Glew
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS+})

#Add a executable
add_executable(untitled1 scr/main.cpp)

#Makes a link to libraries
target_link_libraries(engine ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES} GLEW)