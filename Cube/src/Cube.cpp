//
// Created by Alexian on 16/12/2017.
//

#include "Cube.hpp"

//Cube(const glm::vec3& lower, const glm::vec3& upper);

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
    _indiceVec.push_back(0);
    _indiceVec.push_back(1);
    _indiceVec.push_back(2);
    _indiceVec.push_back(0);
    _indiceVec.push_back(2);
    _indiceVec.push_back(3);

    //face arriere
    _indiceVec.push_back(4);
    _indiceVec.push_back(5);
    _indiceVec.push_back(6);
    _indiceVec.push_back(4);
    _indiceVec.push_back(6);
    _indiceVec.push_back(7);

    //face droit
    _indiceVec.push_back(0);
    _indiceVec.push_back(1);
    _indiceVec.push_back(4);
    _indiceVec.push_back(1);
    _indiceVec.push_back(4);
    _indiceVec.push_back(5);

    //face gauche
    _indiceVec.push_back(2);
    _indiceVec.push_back(3);
    _indiceVec.push_back(7);
    _indiceVec.push_back(2);
    _indiceVec.push_back(6);
    _indiceVec.push_back(7);

    //face haut
    _indiceVec.push_back(0);
    _indiceVec.push_back(3);
    _indiceVec.push_back(4);
    _indiceVec.push_back(3);
    _indiceVec.push_back(4);
    _indiceVec.push_back(7);

    //face bas
    _indiceVec.push_back(1);
    _indiceVec.push_back(2);
    _indiceVec.push_back(5);
    _indiceVec.push_back(2);
    _indiceVec.push_back(5);
    _indiceVec.push_back(6);

    /*position*/
    _position = _vertexVec.push_back(glm::vec3(lower.x, upper.y, lower.z));
}