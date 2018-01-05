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
        _direction = glm::vec3(0,0,-0.3);
    }

    Fantome (glm::vec3 pos, float radius, glimac::FilePath &appPath){
        _PersoObj = glimac::Sphere(radius, 30, 30);
        _pos = _posInitiale = pos;
        _etat = 0;
        _direction = glm::vec3(0,0,-0.3);

        _program = Prog(appPath, "3D", "tex3D4");
        _program.addUniform("uMVMatrix");
        _program.addUniform("uMVPMatrix");
        _program.addUniform("uNormalMatrix");
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

    void deplacement(float distX, float distY);

private:
    int _etat;
};


#endif //IMACMAN_FANTOME_H
