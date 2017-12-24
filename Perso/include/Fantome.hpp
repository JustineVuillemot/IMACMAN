//
// Created by Alexian on 16/12/2017.
//

#include "Personnage.h"

#ifndef IMACMAN_FANTOME_H
#define IMACMAN_FANTOME_H


class Fantome : public Personnage{
public:

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
