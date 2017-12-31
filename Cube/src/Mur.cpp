//
// Created by Alexian on 16/12/2017.
//

#include "../include/Mur.hpp"

//position must be the left top back corner of the cube
Mur::Mur(const glm::vec3 position, const float width, const float height, const float depth){
    _width = width;
    _height = height;
    _depth = depth;
    _position = position;

    glm::vec3 lower = glm::vec3(position.x, position.y-height, position.z);
    glm::vec3 upper = glm::vec3(position.x+width, position.y, position.z+depth);

    generateVertices(lower, upper);
    generateIndexs();
}