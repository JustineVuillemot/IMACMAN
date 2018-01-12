#ifndef IMACGL_SUPERPACGOMME_HPP
#define IMACGL_SUPERPACGOMME_HPP

#include "Objet.hpp"

class SuperPacGomme : public Objet{
public:
    SuperPacGomme(){}

    SuperPacGomme(glm::vec3 pos, float radius){
        _obj = glimac::Sphere(radius, 30, 30);
        _position = pos;
        _etat = 2;
        _nbrPoint = 100;
    }

    SuperPacGomme(glm::vec3 pos, float radius, glimac::FilePath &appPath){
        _obj = glimac::Sphere(radius, 30, 30);
        _position = pos;
        _etat = 2;
        _nbrPoint = 100;
        _program = Prog(appPath, "3D", "directionallight");
        _program.addUniform("uMVMatrix");
        _program.addUniform("uMVPMatrix");
        _program.addUniform("uNormalMatrix");
        _program.addUniform("uTexture");
        _texture = Texture("../../asset/Textures/superpacgommetest.jpg");
        _program.addUniform("uKs");
        _program.addUniform("uShininess");
        _program.addUniform("uLightDir_vs");
        _program.addUniform("uLightIntensity");
    }

    int getNbrPoint() override{
        return _nbrPoint;
    }

    void revive() override{
        _etat = 2;
    }
};

#endif //IMACGL_SUPERPACGOMME_HPP
