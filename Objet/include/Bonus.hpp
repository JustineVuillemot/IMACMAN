//
// Created by Alexian on 16/12/2017.
//

#include "Objet.hpp"

#ifndef IMACMAN_BONUS_H
#define IMACMAN_BONUS_H


class Bonus : public Objet{
public:
    Bonus(){}
    Bonus(glm::vec3 pos, float radius){
        _obj = glimac::Sphere(radius, 30, 30);
        _position = pos;
        _etat = 3;
        _nbrPoint = 5;
    }

    Bonus(glm::vec3 pos, float radius, glimac::FilePath &appPath){
        _obj = glimac::Sphere(radius, 30, 30);
        _position = pos;
        _etat = 3;
        _nbrPoint = 5;
        _program = Prog(appPath, "3D", "tex3D3");
        _program.addUniform("uMVMatrix");
        _program.addUniform("uMVPMatrix");
        _program.addUniform("uNormalMatrix");
        _program.addUniform("uTexture");
        _texture = Texture("../../asset/Textures/pacmantest.jpg");
    }
};


#endif //IMACMAN_BONUS_H
