//
// Created by Alexian on 16/12/2017.
//

#include "Cube.hpp"

Cube::Cube(const glm::vec3 &lower, const glm::vec3 &upper){

    /*remplissage de vertexVec avec les 8 points*/
    //face AVANT
    _vertexVec.push_back(ShapeVertex(upper, glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0))); //haut droit
    _vertexVec.push_back(ShapeVertex(glm::vec3(upper.x, lower.y, upper.z), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0))); // bas droit
    _vertexVec.push_back(ShapeVertex(glm::vec3(lower.x, lower.y, upper.z), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0))); // bas gauche
    _vertexVec.push_back(ShapeVertex(glm::vec3(lower.x, upper.y, upper.z), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0))); // haut gauche

    //face ARRIERE
    _vertexVec.push_back(ShapeVertex(glm::vec3(upper.x, upper.y, lower.z), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0))); //haut droit
    _vertexVec.push_back(ShapeVertex(glm::vec3(upper.x, lower.y, lower.z), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0))); // bas droit
    _vertexVec.push_back(ShapeVertex(lower, glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0))); // bas gauche
    _vertexVec.push_back(ShapeVertex(glm::vec3(lower.x, upper.y, lower.z), glm::vec3(0.0, 0.0, 1.0), glm::vec2(0,0))); // haut gauche

    /*remplissage de l'indiceVec*/
    //face avant
    _indexVec.push_back(0);
    _indexVec.push_back(1);
    _indexVec.push_back(2);
    _indexVec.push_back(0);
    _indexVec.push_back(2);
    _indexVec.push_back(3);

    //face arriere
    _indexVec.push_back(4);
    _indexVec.push_back(5);
    _indexVec.push_back(6);
    _indexVec.push_back(4);
    _indexVec.push_back(6);
    _indexVec.push_back(7);

    //face droit
    _indexVec.push_back(0);
    _indexVec.push_back(1);
    _indexVec.push_back(4);
    _indexVec.push_back(1);
    _indexVec.push_back(4);
    _indexVec.push_back(5);

    //face gauche
    _indexVec.push_back(2);
    _indexVec.push_back(3);
    _indexVec.push_back(7);
    _indexVec.push_back(2);
    _indexVec.push_back(6);
    _indexVec.push_back(7);

    //face haut
    _indexVec.push_back(0);
    _indexVec.push_back(3);
    _indexVec.push_back(4);
    _indexVec.push_back(3);
    _indexVec.push_back(4);
    _indexVec.push_back(7);

    //face bas
    _indexVec.push_back(1);
    _indexVec.push_back(2);
    _indexVec.push_back(5);
    _indexVec.push_back(2);
    _indexVec.push_back(5);
    _indexVec.push_back(6);

    /*position*/
    _position = glm::vec3(lower.x, upper.y, lower.z);
}

void Cube::remplirBuffers(){
    c_vbo.remplirBuffer(_vertexVec);
    c_ibo.remplirBuffer(_indexVec);
    c_vao.remplirBuffer(_vertexVec, &c_vbo, &c_ibo);

}

void Cube::draw(){
    c_vao.bind();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    c_vao.debind();
}