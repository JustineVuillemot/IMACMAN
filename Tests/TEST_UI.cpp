#define GLEW_STATIC
#include <iostream>
#include <fstream>
#include <string>
#include <GL/glew.h>
#include <GL/glut.h>
#include <memory>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <glimac/Sphere.hpp>
#include <glimac/Program.hpp>
#include <glimac/Image.hpp>
#include <glimac/SDLWindowManager.hpp>
#include <glimac/TrackballCamera.hpp>
#include "Jeu.hpp"
#include "UI.hpp"
#include "Menu.hpp"

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

    if(TTF_Init() == -1){
        std::cerr << TTF_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    FilePath applicationPath(argv[0]);
    Program progUI = loadProgram(applicationPath.dirPath() + "shaders/triangle.vs.glsl",
                                  applicationPath.dirPath() + "shaders/triangle.fs.glsl");

    UI points;

    try{
        points = UI("../../asset/arialbd.ttf", glm::vec2(-0.8, 0.8), "Points : 0");
    }
    catch(const std::invalid_argument &err){
        std::cerr << err.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    UI vies;

    try{
        vies = UI("../../asset/arialbd.ttf", glm::vec2(0.6, 0.8), "Vies : 3");
    }
    catch(const std::invalid_argument &err){
        std::cerr << err.what() << std::endl;
        exit(EXIT_FAILURE);
    }

    /*UNIFORMES*/
    GLuint uTexUI = glGetUniformLocation(progUI.getGLId(), "uTexture");

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Menu pauseMenu;

    try{
        pauseMenu = Menu("../../asset/arialbd.ttf");
    }
    catch(const std::invalid_argument &err){
        std::cerr << err.what() << std::endl;
        exit(EXIT_FAILURE);
    }


    Jeu jeu;

    try{
        jeu = Jeu("../../Level/Level2.txt", 1.f, 1.f);
    }
    catch(const std::string &s){
        std::cerr << "Erreur : " << s << std::endl;
    }

    jeu.addElement(applicationPath);
    jeu.remplirBuffer();


    glm::mat4 modelViewMat, normalMat, mvProjMat;

    TrackballCamera cam;
    bool rotatebutton = false;
    bool moveLeft = false;
    bool moveRight = false;
    bool moveUp = false;
    bool moveDown = false;
    bool menu = true;

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;

        if(menu){
            while(windowManager.pollEvent(e)) {
                if (e.type == SDL_KEYDOWN && e.key.keysym.sym == 27) {
                    menu = !menu;
                    //std::cout << "menu change" << std::endl;
                }
                if(e.type == SDL_QUIT) {
                    done = true; // Leave the loop after this iteration
                }
            }
        }else{

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
                if (e.key.keysym.sym == 27) {
                    menu = !menu;
                    //std::cout << "menu change" << std::endl;
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

        //PACMAN
        if(moveLeft == true){
            if(jeu.collisionManager(glm::vec3(-0.3,0,0)) == 3){
                jeu._pacman[0]->moveLeft(0.005f);
            }
            jeu._pacman[0]->moveLeft(-0.005f);
            jeu._pacman[0]->rotatePerso(270.f);
        }
        if(moveRight == true){
            if(jeu.collisionManager(glm::vec3(0.3,0,0)) == 3){
                jeu._pacman[0]->moveLeft(-0.005f);
            }
            jeu._pacman[0]->moveLeft(0.005f);
            jeu._pacman[0]->rotatePerso(90.f);
        }
        if(moveUp == true){
            if(jeu.collisionManager(glm::vec3(0,0,-0.3)) == 3){
                jeu._pacman[0]->moveUp(0.005f);
            }
            jeu._pacman[0]->moveUp(-0.005f);
            jeu._pacman[0]->rotatePerso(0.f);
        }
        if(moveDown == true){
            if(jeu.collisionManager(glm::vec3(0,0,0.3)) == 3){
                jeu._pacman[0]->moveUp(-0.005f);
            }
            jeu._pacman[0]->moveUp(0.005f);
            jeu._pacman[0]->rotatePerso(180.f);
        }

        //FANTOMES
        jeu.deplacementFantome(windowManager.getTime());

        }

        modelViewMat = cam.getViewMatrix();
        mvProjMat = glm::perspective(glm::radians(70.f), width/height, 0.1f, 100.f);
        normalMat = glm::transpose(glm::inverse(modelViewMat));

        glClear(GL_COLOR_BUFFER_BIT);

        jeu.draw(modelViewMat, normalMat, mvProjMat, cam.getViewMatrix());

        //UI
        progUI.use();
        glUniform1i(uTexUI, 0);
        points.draw();
        vies.draw();

        if(menu){
            pauseMenu.draw();
        }

        points.refreshText("Points : "+std::to_string(jeu.getScore()));
        vies.refreshText("Vies : "+std::to_string(jeu._pacman[0]->getVie()));

        // Update the display
        windowManager.swapBuffers();
    }

    jeu.freeJeu();

    TTF_Quit();

    return EXIT_SUCCESS;
}
