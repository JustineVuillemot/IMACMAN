#include "Menu.hpp"

Menu::Menu(std::string fontPath){

    generateVertices();
    generateIndexs();
    remplirBuffers();

    try{
        _reTryGame = UI(fontPath, glm::vec2(-0.4, 0.4), "Recommencer le niveau");
        _saveGame = UI(fontPath, glm::vec2(-0.4, 0.1), "Sauvegarder la partie");
        _loadGame = UI(fontPath, glm::vec2(-0.4, -0.2), "Charger une partie");
    }
    catch(const std::invalid_argument &err){
        throw err;
    }
}

void Menu::generateVertices(){
    _vertexVec.push_back(ShapeVertex(glm::vec3(-2, 2, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
    _vertexVec.push_back(ShapeVertex(glm::vec3(2, 2, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
    _vertexVec.push_back(ShapeVertex(glm::vec3(2, -2, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
    _vertexVec.push_back(ShapeVertex(glm::vec3(-2, -2, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
}

void Menu::generateIndexs(){
    _indexVect.push_back(0);
    _indexVect.push_back(1);
    _indexVect.push_back(2);
    _indexVect.push_back(0);
    _indexVect.push_back(2);
    _indexVect.push_back(3);
}

void Menu::draw(){
    m_vao.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    m_vao.debind();

    /*_reTryGame.draw();
    _saveGame.draw();
    _loadGame.draw();*/
}