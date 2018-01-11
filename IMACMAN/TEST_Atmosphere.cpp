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
#include "Atmo.hpp"

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    float width = 800;
    float height = 800;
    SDLWindowManager windowManager(width, height, "GLImac");

    glEnable(GL_DEPTH_TEST);

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    FilePath applicationPath(argv[0]);
    /*Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                                  applicationPath.dirPath() + "shaders/tex3D.fs.glsl");
    program.use();*/

    /*UNIFORMES*/
    /*GLuint uMVMatrix = glGetUniformLocation(program.getGLId(), "uMVMatrix");
    GLuint uMVPMatrix = glGetUniformLocation(program.getGLId(), "uMVPMatrix");
    GLuint uNormalMatrix = glGetUniformLocation(program.getGLId(), "uNormalMatrix");*/

    Jeu jeu;

    try{
        jeu = Jeu("../../Level/Level1.txt", 1.f, 1.f);
    }
    catch(const std::string &s){
        std::cerr << "Erreur : " << s << std::endl;
    }

    Atmo atmo = Atmo(glm::vec3(0,0,0), 50, applicationPath);
    atmo.remplirBuffers();

    jeu.addElement(applicationPath);
    jeu.remplirBuffer();

    glm::mat4 modelViewMat, normalMat, mvProjMat;

    TrackballCamera cam;
    bool rotatebutton = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool moveUp = false;
    bool moveDown = false;


    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_KEYDOWN){
                if(e.key.keysym.sym == SDLK_LEFT){
                    cam.rotateLeft(5.0);
                }
                else if(e.key.keysym.sym == SDLK_RIGHT){
                    cam.rotateLeft(-5.0);
                }
                else if(e.key.keysym.sym == SDLK_UP){
                    cam.rotateUp(5.0);
                }
                else if(e.key.keysym.sym == SDLK_DOWN){
                    cam.rotateUp(-5.0);
                }
                if (e.key.keysym.sym == 119  && e.key.state == SDL_PRESSED) { // Z
                    moveUp = true;
                } else if (e.key.keysym.sym == 115  && e.key.state == SDL_PRESSED) { // S
                    moveDown = true;
                }
                if (e.key.keysym.sym == 97 && e.key.state == SDL_PRESSED) { // Q
                    moveLeft = true;
                } else if (e.key.keysym.sym == 100  && e.key.state == SDL_PRESSED) { // D
                    moveRight = true;
                }
            }
            if(e.type == SDL_KEYUP){
                if (e.key.keysym.sym == 119  && e.key.state == SDL_RELEASED) { // Z
                    moveUp = false;
                } else if (e.key.keysym.sym == 115  && e.key.state == SDL_RELEASED) { // S
                    moveDown = false;
                }
                if (e.key.keysym.sym == 97 && e.key.state == SDL_RELEASED) { // Q
                    moveLeft = false;
                } else if (e.key.keysym.sym == 100  && e.key.state == SDL_RELEASED) { // D
                    moveRight = false;
                }
            }
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

        if(moveLeft == true){
            if(jeu.collisionManager(glm::vec3(-0.3,0,0), windowManager.getTime()) == 3){
                jeu._pacman[0]->moveLeft(0.005f);
            }
            jeu._pacman[0]->moveLeft(-0.005f);
            jeu._pacman[0]->rotatePerso(270.f);
        }
        else if(moveRight == true){
            if(jeu.collisionManager(glm::vec3(0.3,0,0), windowManager.getTime()) == 3){
                jeu._pacman[0]->moveLeft(-0.005f);
            }
            jeu._pacman[0]->moveLeft(0.005f);
            jeu._pacman[0]->rotatePerso(90.f);
        }
        else if(moveUp == true){
            if(jeu.collisionManager(glm::vec3(0,0,-0.3), windowManager.getTime()) == 3){
                jeu._pacman[0]->moveUp(0.005f);
            }
            jeu._pacman[0]->moveUp(-0.005f);
            jeu._pacman[0]->rotatePerso(0.f);
        }
        else if(moveDown == true){
            if(jeu.collisionManager(glm::vec3(0,0,0.3), windowManager.getTime()) == 3){
                jeu._pacman[0]->moveUp(-0.005f);
            }
            jeu._pacman[0]->moveUp(0.005f);
            jeu._pacman[0]->rotatePerso(180.f);
        }
        else{
            //necessaire pour que pacman meurt s'il ne bouge pas
            jeu.collisionManager(glm::vec3(0.0,0,0), windowManager.getTime());
        }

        if(jeu._pacman[0]->getVie() == 0){ //FIN DU JEU
            done = true;
        }

        if(jeu.getTimePacman() != 0 && atmo.getEtat() == 0){
            atmo.setEtat(1);
        }

        if(windowManager.getTime() - jeu.getTimePacman() > 8.0 && jeu.getTimePacman() != 0){ //La superPacGomme dure 8 secondes
            std::cout << "FIN DE L'EFFET" << std::endl;
            jeu._pacman[0]->setEtat(0);
            jeu.setTimePacman(0);
            atmo.setEtat(0);
        }

        //FANTOMES
        jeu.deplacementFantome(windowManager.getTime() - jeu.getTimeTouch());

        modelViewMat = cam.getViewMatrix();
        mvProjMat = glm::perspective(glm::radians(70.f), width/height, 0.1f, 100.f);
        normalMat = glm::transpose(glm::inverse(modelViewMat));

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        atmo._program.use();
        if(atmo.getEtat() == 0){
            atmo._program.sendUniform1i(atmo._texture1._texture, 0);
            modelViewMat = atmo.getViewMatrix(cam.getViewMatrix());
            atmo._program.sendUniformMatrix4fv("uMVMatrix", modelViewMat);
            atmo._program.sendUniformMatrix4fv("uNormalMatrix", normalMat);
            atmo._program.sendUniformMatrix4fv("uMVPMatrix", mvProjMat*modelViewMat);
            atmo._texture1.bind();
            atmo.draw();
            atmo._texture1.debind();
        }
        else{
            atmo._program.sendUniform1i(atmo._texture2._texture, 0);
            modelViewMat = atmo.getViewMatrix(cam.getViewMatrix());
            atmo._program.sendUniformMatrix4fv("uMVMatrix", modelViewMat);
            atmo._program.sendUniformMatrix4fv("uNormalMatrix", normalMat);
            atmo._program.sendUniformMatrix4fv("uMVPMatrix", mvProjMat*modelViewMat);
            atmo._texture2.bind();
            atmo.draw();
            atmo._texture2.debind();
        }


        jeu.draw(modelViewMat, normalMat, mvProjMat, cam.getViewMatrix());

        // Update the display
        windowManager.swapBuffers();
    }

    jeu.freeJeu();
    return EXIT_SUCCESS;
}
