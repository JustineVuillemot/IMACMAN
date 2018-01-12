//
// Created by Alexian on 16/12/2017.
//

#include "../include/Fantome.hpp"

int Fantome::collisionCube(Cube &cube, glm::vec3 direction) {
    glm::vec3 posCube = cube.getPosition();
    if(direction.x != 0 && direction.x >= 0){ //MOVE RIGHT
        if(_pos.y < posCube.y && _pos.y > posCube.y - 1.4
           && _pos.z > posCube.z - 0.495 && _pos.z  < posCube.z + 1.495
           && _pos.x + 0.01 > posCube.x - 0.5 && _pos.x + 0.01 < posCube.x +1){
            return 1;
        }
    }
    if(direction.x != 0 && direction.x < 0){ //MOVE LEFT
        if(_pos.y < posCube.y && _pos.y > posCube.y - 1.4
           && _pos.z > posCube.z - 0.495 && _pos.z  < posCube.z + 1.495
           && _pos.x - 0.01 < posCube.x + 1.5 && _pos.x - 0.01 > posCube.x){
            return 1;
        }
    }
    if(direction.z != 0 && direction.z >= 0){ //MOVE DOWN
        if(_pos.y < posCube.y && _pos.y > posCube.y - 1.4
           && _pos.x > posCube.x - 0.495 && _pos.x < posCube.x + 1.495
           && _pos.z + 0.01 > posCube.z - 0.495 && _pos.z + 0.01 < posCube.z +1){
            return 1;
        }
    }
    if(direction.z != 0 && direction.z < 0){ //MOVE UP
        if(_pos.y < posCube.y && _pos.y > posCube.y - 1.4
           && _pos.x > posCube.x - 0.495 && _pos.x  < posCube.x + 1.495
           && _pos.z - 0.01 < posCube.z + 1.5 && _pos.z - 0.01 > posCube.z){
            return 1;
        }
    }
    return 0;
}

void Fantome::deplacement(float distX, float distY) {
    setPos(getPos() + glm::vec3(distX, distY, 0));
}