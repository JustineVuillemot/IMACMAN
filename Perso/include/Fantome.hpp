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
        _randDirection = 1.f;
        _direction = glm::vec3(0,0,-0.3);
    }

    Fantome (glm::vec3 pos, float radius, glimac::FilePath &appPath){
        _PersoObj = glimac::Sphere(radius, 30, 30);
        _pos = _posInitiale = pos;
        _etat = 0;
        _randDirection = 1.f;
        _direction = glm::vec3(0,0,-0.3);

        _program = Prog(appPath, "3D", "directionallight");
        _program.addUniform("uMVMatrix");
        _program.addUniform("uMVPMatrix");
        _program.addUniform("uNormalMatrix");
        _program.addUniform("uTexture");
        _texture = Texture("../../asset/Textures/fantome1.jpg");
        _texture2 = Texture("../../asset/Textures/fantome2.jpg");
        _program.addUniform("uKs");
        _program.addUniform("uShininess");
        _program.addUniform("uLightDir_vs");
        _program.addUniform("uLightIntensity");
    }


    /* METHODS */
    int collisionCube(Cube &cube, glm::vec3 direction) override;
    void deplacement(float distX, float distY);

};


#endif //IMACMAN_FANTOME_H
