
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
    ~UI(){
        SDL_FreeSurface(_texteSurface);
    };

    UI(std::string fontPath, glm::vec2 position, std::string texte);

    void generateSurface(std::string texte);
    void generateTexture();

    void generateVertices();
    void generateIndexs();
    void remplirBuffers(){
        ui_vbo.remplirBuffer(_vertexVec);
        ui_ibo.remplirBuffer(_indexVect);
        ui_vao.remplirBuffer(_vertexVec, &ui_vbo, &ui_ibo);
    }

    void refreshText(std::string texte);
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
    SDL_Surface* _texteSurface;
    std::string _fontPath;
    Texture _texture;
    std::vector<ShapeVertex> _vertexVec;
    std::vector<uint32_t> _indexVect;
};

#endif //IMACGL_UI_HPP
