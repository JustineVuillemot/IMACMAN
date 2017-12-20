//
// Created by Alexian on 16/12/2017.
//

#include "Cube.h"

#ifndef IMACMAN_MUR_H
#define IMACMAN_MUR_H


class Mur : public Cube {
public:

    /* GETTER */

    float getEpaisseur(){
        return _epaisseur;
    }
    int getOrientation(){
        return _orientation;
    }

    /* SETTER */

    void setEpaisseur(float epaisseur){
        _epaisseur = epaisseur;
    }
    void setOrientation(int orientation){
        _orientation = orientation;
    }
private:
    float _epaisseur;
    int _orientation;
};


#endif //IMACMAN_MUR_H
