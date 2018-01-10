
#ifndef IMACGL_UI_HPP
#define IMACGL_UI_HPP

#include <string>
#include "SDL.h"
#include "SDL_ttf.h"
#include "VBO.hpp"
#include "VAO.hpp"
#include "IBO.hpp"
#include "Texture.hpp"

using namespace glimac;

class UI {
public:

    UI(){};
    ~UI() = default;

    UI(std::string fontPath, glm::vec2 position);

    void generateSurface();
    void generateTexture();
    void draw();

    /* GETTER */
    glm::vec2 getPosition(){
        return _position;
    }

    /* SETTER */

    void setPositon(glm::vec2 position){
        _position = position;
    }

private:
    glm::vec2 _position;
    VBO ui_vbo;
    IBO ui_ibo;
    VAO ui_vao;
    SDL_Surface* _texte;
    std::string _fontPath;
    Texture _texture;

};

#endif //IMACGL_UI_HPP
