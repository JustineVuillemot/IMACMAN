//
// Created by Alexian on 16/12/2017.
//

#include "../include/Fantome.hpp"

void Fantome::deplacement(float distX, float distY) {
    setPos(getPos() + glm::vec3(distX, distY, 0));
}