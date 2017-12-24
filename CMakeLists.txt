cmake_minimum_required(VERSION 2.8)

project(ImacGL)

add_definitions(-std=c++11)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake)

find_package(SDL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${SDL_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLEW_INCLUDE_DIR} glimac/include third-party/include Cube/include Jeu/include Objet/include Perso/include Prog/include)

#set(ALL_LIBRARIES glimac ${SDL_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY} glu32 freeglut)
set(ALL_LIBRARIES mingw32 glimac SDL glew32s opengl32 glu32 freeglut) #add the libraries options in the LIB_LIST variable
add_subdirectory(glimac)

file(GLOB TP_DIRECTORIES "IMACMAN")

foreach(TP ${TP_DIRECTORIES})
    add_subdirectory(${TP})
endforeach()

