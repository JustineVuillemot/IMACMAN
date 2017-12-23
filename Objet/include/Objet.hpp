//
// Created by Alexian on 16/12/2017.
//

#include <glm/glm.hpp>

#ifndef IMACMAN_OBJET_H
#define IMACMAN_OBJET_H


class Objet {
public:
    /* GETTER */

    int getNbrPoint(){
        return _nbrPoint;
    }
    glm::vec3 getPosition(){
        return _position;
    }
    int getEtat(){
        return _etat;
    }

    /* SETTER */

    void setNbrPoint(int nbrPoint){
        _nbrPoint = nbrPoint;
    }
    void setPosition(glm::vec3 position){
        _position = position;
    }
    void setEtat(int etat){
        _etat = etat;
    }

private:
    int _nbrPoint;
    glm::vec3 _position;
    int _etat;
};


#endif //IMACMAN_OBJET_H
