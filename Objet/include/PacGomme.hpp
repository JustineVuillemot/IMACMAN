//
// Created by Alexian on 16/12/2017.
//

#include "Objet.hpp"

#ifndef IMACMAN_PACGOMME_H
#define IMACMAN_PACGOMME_H


class PacGomme : public Objet{
public:
    PacGomme(){}

    PacGomme(glm::vec3 pos, float radius){
        _obj = glimac::Sphere(radius, 30, 30);
        _position = pos;
        _etat = 1;
        _nbrPoint = 5;
    }

    PacGomme(glm::vec3 pos, float radius, glimac::FilePath &appPath){
        _obj = glimac::Sphere(radius, 30, 30);
        _position = pos;
        _etat = 1;
        _nbrPoint = 5;
        _program = Prog(appPath, "3D", "tex3D");
        _program.addUniform("uMVMatrix");
        _program.addUniform("uMVPMatrix");
        _program.addUniform("uNormalMatrix");
    }
};


#endif //IMACMAN_PACGOMME_H
