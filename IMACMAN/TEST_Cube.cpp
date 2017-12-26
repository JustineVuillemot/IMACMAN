//
// Created by justine on 24/12/2017.
//

#define GLEW_STATIC
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <memory>
#include <SDL/SDL.h>
#include <glimac/Sphere.hpp>
#include <glimac/Program.hpp>
#include <glimac/Image.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/TrackballCamera.hpp>
#include "Buffer.hpp"
#include "VBO.hpp"
#include "VAO.hpp"
#include "IBO.hpp"
#include "Cube.hpp"

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    float width = 800;
    float height = 800;
    SDLWindowManager windowManager(width, height, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                                  applicationPath.dirPath() + "shaders/tex3D.fs.glsl");
    program.use();

    /*UNIFORMES*/
    GLuint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLuint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLuint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");

    VBO vbo = VBO();
    VAO vao = VAO();
    IBO ibo = IBO();
    Cube cube = Cube(glm::vec3(-0.5f, -0.2f, -0.5f), glm::vec3(0.5f, 0.2f, 0.5f));

    std::vector<ShapeVertex> vertices;
    vertices = cube.getVertexVec();

    std::vector<uint32_t> indices;
    indices = cube.getIndexVec();

    vbo.remplirBuffer(vertices);

    ibo.remplirBuffer(indices);

    vao.remplirBuffer(vertices, &vbo, &ibo);

    glm::mat4 modelViewMat, normalMat, mvProjMat;

    TrackballCamera cam;
    bool rotatebutton;

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_WHEELUP){
                cam.moveFront(1);
            }
            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_WHEELDOWN){
                cam.moveFront(-1);
            }
            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT){
                rotatebutton = true;
            }
            if(e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_RIGHT){
                rotatebutton = false;
            }
            if(e.type == SDL_MOUSEMOTION && rotatebutton){
                cam.rotateLeft(e.motion.xrel);
                cam.rotateUp(e.motion.yrel);
            }
        }

        modelViewMat = cam.getViewMatrix();
        mvProjMat = glm::perspective(glm::radians(70.f), width/height, 0.1f, 100.f);
        normalMat = glm::transpose(glm::inverse(modelViewMat));

        /*UNFORMES*/
        glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(modelViewMat));
        glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(normalMat));
        glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(mvProjMat*modelViewMat));

        glClear(GL_COLOR_BUFFER_BIT);

        vao.bind();

        // => On utilise glDrawElements à la place de glDrawArrays
        // Cela indique à OpenGL qu'il doit utiliser l'IBO enregistré dans le VAO
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        vao.debind();

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
