//
// Created by Alexian on 16/12/2017.
//

#include <GL/glew.h>
#include <glimac/common.hpp>
#include "Cube.hpp"

Cube::Cube(const glm::vec3 &lower,const glm::vec3 &upper){

    generateVertices(lower, upper);
    generateIndexs();

    _position = glm::vec3(lower.x, upper.y, lower.z);
}

//Cube::Cube(const glm::vec3 &lower,const glm::vec3 &upper, glimac::FilePath appPath)

void Cube::generateVertices(const glm::vec3 &lower, const glm::vec3 &upper){
    //face AVANT
    _vertexVec.push_back(ShapeVertex(upper, upper - _position, glm::vec2(1,1))); //haut droit
    _vertexVec.push_back(ShapeVertex(glm::vec3(upper.x, lower.y, upper.z), glm::vec3(upper.x, lower.y, upper.z) - _position, glm::vec2(1,0))); // bas droit
    _vertexVec.push_back(ShapeVertex(glm::vec3(lower.x, lower.y, upper.z), glm::vec3(lower.x, lower.y, upper.z) - _position, glm::vec2(0,0))); // bas gauche
    _vertexVec.push_back(ShapeVertex(glm::vec3(lower.x, upper.y, upper.z), glm::vec3(lower.x, upper.y, upper.z) - _position, glm::vec2(0,1))); // haut gauche

    //face ARRIERE
    _vertexVec.push_back(ShapeVertex(glm::vec3(upper.x, upper.y, lower.z), glm::vec3(upper.x, upper.y, lower.z) - _position, glm::vec2(1,1))); //haut droit
    _vertexVec.push_back(ShapeVertex(glm::vec3(upper.x, lower.y, lower.z), glm::vec3(upper.x, lower.y, lower.z) - _position, glm::vec2(1,0))); // bas droit
    _vertexVec.push_back(ShapeVertex(lower, lower - _position, glm::vec2(0,0))); // bas gauche
    _vertexVec.push_back(ShapeVertex(glm::vec3(lower.x, upper.y, lower.z), glm::vec3(lower.x, upper.y, lower.z) - _position, glm::vec2(0,1))); // haut gauche
}

void Cube::generateIndexs(){
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
}

void Cube::draw(){
    c_vao.bind();
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    c_vao.debind();
}