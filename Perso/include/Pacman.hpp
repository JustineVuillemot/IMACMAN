//
// Created by Alexian on 16/12/2017.
//

#include "Personnage.hpp"

#ifndef IMACMAN_PACMAN_H
#define IMACMAN_PACMAN_H


class Pacman : public Personnage {
public:

    /* GETTER */

    int getVie(){
        return _vie;
    }

    /* SETTER */

    void setVie(int vie){
        _vie = vie;
    }

    /* METHODS */

    void moveLeft(float distance);
    void moveRight(float distance);
private:
    int _vie;
};


#endif //IMACMAN_PACMAN_H
