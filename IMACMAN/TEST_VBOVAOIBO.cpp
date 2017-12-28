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
#include "Buffer.hpp"
#include "VBO.hpp"
#include "VAO.hpp"
#include "IBO.hpp"

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/triangle.vs.glsl",
                                  applicationPath.dirPath() + "shaders/triangle.fs.glsl");
    program.use();

    VBO vbo = VBO();
    VAO vao = VAO();
    IBO ibo = IBO();

    // => Tableau de sommets : un seul exemplaire de chaque sommet
    std::vector<ShapeVertex> vertices;
    vertices.push_back(ShapeVertex(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
    vertices.push_back(ShapeVertex(glm::vec3(0.5, -0.5, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
    vertices.push_back(ShapeVertex(glm::vec3(0.5, 0.5, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
    vertices.push_back(ShapeVertex(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));

    vbo.remplirBuffer(vertices);


    // => Tableau d'indices: ce sont les indices des sommets à dessiner
    // On en a 6 afin de former deux triangles
    // Chaque indice correspond au sommet correspondant dans le VBO
    std::vector<uint32_t> indices;
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(0);
    indices.push_back(2);
    indices.push_back(3);


    ibo.remplirBuffer(indices);

    vao.remplirBuffer(vertices, &vbo, &ibo);

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        glClear(GL_COLOR_BUFFER_BIT);

        vao.bind();

        // => On utilise glDrawElements à la place de glDrawArrays
        // Cela indique à OpenGL qu'il doit utiliser l'IBO enregistré dans le VAO
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        vao.debind();

        // Update the display
        windowManager.swapBuffers();
    }

    return EXIT_SUCCESS;
}
