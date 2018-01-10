#include "UI.hpp"

//position est le coin haut gauche
UI::UI(std::string fontPath, glm::vec2 position){
    _fontPath = fontPath;
    _position = position;
    generateSurface();
    generateTexture();

    float width = ((float)_texte->w/300);
    float height = ((float)_texte->h/300);

    std::vector<ShapeVertex> vertices;
    vertices.push_back(ShapeVertex(glm::vec3(_position.x, _position.y, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
    vertices.push_back(ShapeVertex(glm::vec3(_position.x + width, _position.y, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(1,0)));
    vertices.push_back(ShapeVertex(glm::vec3(_position.x + width, _position.y - height, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(1,1)));
    vertices.push_back(ShapeVertex(glm::vec3(_position.x, _position.y - height, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,1)));

    ui_vbo.remplirBuffer(vertices);

    std::vector<uint32_t> indices;
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);
    indices.push_back(0);
    indices.push_back(2);
    indices.push_back(3);


    ui_ibo.remplirBuffer(indices);

    ui_vao.remplirBuffer(vertices, &ui_vbo, &ui_ibo);
}

void UI::generateSurface(){
    TTF_Font *police = NULL;
    police = TTF_OpenFont(_fontPath.c_str(), 16);

    SDL_Color white = {255, 255, 255};

    _texte =  TTF_RenderText_Blended(police, "Points : 0", white);

    TTF_CloseFont(police);
}

void UI::generateTexture(){
    _texture = Texture(*_texte);
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