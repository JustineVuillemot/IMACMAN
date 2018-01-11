//
// Created by Alexian on 16/12/2017.
//

#include "../include/Pacman.hpp"

void Pacman::moveLeft(float distance) {
    setPos(getPos() + glm::vec3(distance, 0, 0));
}
void Pacman::moveUp(float distance){
    setPos(getPos() + glm::vec3(0, 0, distance));
}

int Pacman::getEtat() const {
    return _etat;
}

void Pacman::setEtat(int _etat) {
    Pacman::_etat = _etat;
}
