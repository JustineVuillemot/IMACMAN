#include "Menu.hpp"

Menu::Menu(std::string fontPath){

    generateVertices();
    generateIndexs();
    remplirBuffers();

    try{
        _reTryGame = UI(fontPath, glm::vec2(-0.315, 0.18), "Recommencer le niveau");
        _saveGame = UI(fontPath, glm::vec2(-0.28, 0.03), "Sauvegarder la partie");
        _loadGame = UI(fontPath, glm::vec2(-0.25, -0.12), "Charger une partie");
    }
    catch(const std::invalid_argument &err){
        throw err;
    }
}

void Menu::generateVertices(){
    _vertexVec.push_back(ShapeVertex(glm::vec3(-0.4, 0.3, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
    _vertexVec.push_back(ShapeVertex(glm::vec3(0.4, 0.3, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
    _vertexVec.push_back(ShapeVertex(glm::vec3(0.4, -0.3, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
    _vertexVec.push_back(ShapeVertex(glm::vec3(-0.4, -0.3, 0.0), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0)));
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
    generateVertices();
    remplirBuffers();
    m_vao.bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    m_vao.debind();

    _reTryGame.generateVertices();
    _reTryGame.remplirBuffers();
    _reTryGame.draw();

    _saveGame.generateVertices();
    _saveGame.remplirBuffers();
    _saveGame.draw();

    _loadGame.generateVertices();
    _loadGame.remplirBuffers();
    _loadGame.draw();
}