//
// Created by Alexian on 16/12/2017.
//

#include "Personnage.hpp"

#ifndef IMACMAN_FANTOME_H
#define IMACMAN_FANTOME_H


class Fantome : public Personnage{
public:
    Fantome(){}
    Fantome (glm::vec3 pos, float radius){
        _PersoObj = glimac::Sphere(radius, 30, 30);
        _pos = _posInitiale = pos;
        _etat = 0;
    }

    /* GETTER */

    int getEtat(){
        return _etat;
    }

    /* SETTER */

    void setEtat(int etat){
        _etat = etat;
    }

    /* METHODS */

    void deplacement();

private:
    int _etat;
};


#endif //IMACMAN_FANTOME_H
