#include "UI.hpp"


void UI::refreshText(std::string texte){
    try{
        generateSurface(texte);
    }
    catch(const std::invalid_argument &err){
        throw err;
    }

    generateTexture();

    generateVertices();

    remplirBuffers();
}

void UI::generateVertices(){
    float width = ((float)_texteSurface->w/300);
    float height = ((float)_texteSurface->h/300);

    _vertexVec.clear();

    _vertexVec.push_back(ShapeVertex(glm::vec3(_position.x, _position.y, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
    _vertexVec.push_back(ShapeVertex(glm::vec3(_position.x + width, _position.y, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(1,0)));
    _vertexVec.push_back(ShapeVertex(glm::vec3(_position.x + width, _position.y - height, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(1,1)));
    _vertexVec.push_back(ShapeVertex(glm::vec3(_position.x, _position.y - height, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,1)));
}

void UI::generateIndexs(){
    _indexVect.push_back(0);
    _indexVect.push_back(1);
    _indexVect.push_back(2);
    _indexVect.push_back(0);
    _indexVect.push_back(2);
    _indexVect.push_back(3);
}

void UI::generateSurface(std::string texte){
    TTF_Font *police;
    police = TTF_OpenFont(_fontPath.c_str(), 16);

    if(!police){
        throw std::invalid_argument(TTF_GetError());
    }

    SDL_Color white = {1, 1, 1};

    _texteSurface =  TTF_RenderText_Blended(police, texte.c_str(), white);

    TTF_CloseFont(police);
}

void UI::generateTexture(){
    _texture = Texture(*_texteSurface);
}

void UI::draw(){
    glEnable(GL_BLEND);

    ui_vao.bind();
        _texture.bind();
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        _texture.debind();
    ui_vao.debind();

    glDisable(GL_BLEND);
}