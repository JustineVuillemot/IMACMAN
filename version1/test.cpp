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

#ifdef WIN32
void initGLextensions() {
//	glGetString= (PFNGLACTIVETEXTUREARBPROC) wglGetProcAddress("glActiveTextureARB");
}
#include <windows.h>
#else
#include <unistd.h>
#endif

#define ERROR_EXIT(message) std::cerr << message << std::endl; exit(1);


using namespace glm;
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

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    /*Création d'un seul VBO (Vertex Buffer Objet stocké dans
    le GPU et contient les sommets des triangles et ses attributs,
    genre coords, couleurs, normales)*/

    GLuint vbo; // ou vbos[taille] si plusieurs
    glGenBuffers(1, &vbo); // ou glGenBuffers(taille, vbo); si plusieurs

    /*A partir de ce point, la variable vbo contient l'id d'un VBO*/

    /* on binde un buffer à une cible pour pouvoir le modifier
    on peut à présent modifier vbo en passant par sa cible */
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    GLfloat vertices[] = { -0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f };

    //on remplit le vbo avec le tableau des vertex
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);

    /*après avoir modifié le vbo on le debind de la cible pour
    éviter de le modifier par erreur*/
    glBindBuffer(GL_ARRAY_BUFFER, 0); // 0 = vbo "null"

    /*Les données sont à présents stockées dans le GPU
    mais il faut lui dire comment interpreter. C'est la
    spécification de sommet à l'aide d'un Vertex Array Objetc.
    Un VAO décrit pour chaque attribut de sommet (position, couleur, normale, etc.)
     la manière dont ils sont rangés dans un ou plusieurs VBOs. */

    GLuint vao;
    glGenVertexArrays(1, &vao);

    /* on binde ! Il n'y a qu'une seule cible pour les vao et
    qu'un seul vao bindé à la fois*/
    glBindVertexArray(vao);

    /*chaque attribut est identifié par un entier.
     Afin d'indiquer à OpenGL qu'on utilise un attribut donné,
     on utilise la fonction : */
    const GLuint VERTEX_ATTR_POSITION = 0;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);

    /*De cette manière on comprend immédiatement que le 0 correspond
    à l'attribut de sommet identifiant la position. On doit ensuite
    ndiquer à OpenGL où il va trouver les sommets à dessiner,
     et comment lire les informations associé à chaque sommet.*/

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,2 * sizeof(GLfloat),0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    /**********************************/
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

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/

        //on nettoie la fenetre des tours précédents
        glClear(GL_COLOR_BUFFER_BIT);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES,0,3);
        glBindVertexArray(0);


        // Update the display
        windowManager.swapBuffers();
    }

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return EXIT_SUCCESS;
}


