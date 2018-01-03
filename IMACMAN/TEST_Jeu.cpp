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
#include "Cube.hpp"
#include "Jeu.hpp"



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

    Jeu jeu;

    try{
        jeu = Jeu("../../Level/Level1.txt", 1.f, 1.f);
    }
    catch(const std::string &s){
        std::cerr << "Erreur : " << s << std::endl;
    }

    jeu.addElement();
    jeu.remplirBuffer();

    int i;
    int j;
    for(i = 0; i < jeu.get_nbrSub(); ++i){
        for(j = 0; j < jeu.get_nbrSub(); ++j){
            std::cout << jeu._plateau[i][j] << " ";
        }
        std::cout << std::endl;
    }

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

        jeu.draw();

        // Update the display
        windowManager.swapBuffers();
    }

    jeu.freeJeu();
    return EXIT_SUCCESS;
}
