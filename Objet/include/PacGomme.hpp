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
        _nbrPoint = 10;
    }

    PacGomme(glm::vec3 pos, float radius, glimac::FilePath &appPath){
        _obj = glimac::Sphere(radius, 30, 30);
        _position = pos;
        _etat = 1;
        _nbrPoint = 10;
        _program = Prog(appPath, "3D", "directionallight");
        _program.addUniform("uMVMatrix");
        _program.addUniform("uMVPMatrix");
        _program.addUniform("uNormalMatrix");
        _program.addUniform("uTexture");
        _texture = Texture("../../asset/Textures/pacgommetest.jpg");
        _program.addUniform("uKs");
        _program.addUniform("uShininess");
        _program.addUniform("uLightDir_vs");
        _program.addUniform("uLightIntensity");
    }

    int getNbrPoint() override{
        return _nbrPoint;
    }

    void revive() override{
        _etat = 1;
    }
};


#endif //IMACMAN_PACGOMME_H
