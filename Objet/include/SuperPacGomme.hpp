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
        _nbrPoint = 5;
    }

    SuperPacGomme(glm::vec3 pos, float radius, glimac::FilePath &appPath){
        _obj = glimac::Sphere(radius, 30, 30);
        _position = pos;
        _etat = 2;
        _nbrPoint = 5;
        _program = Prog(appPath, "3D", "tex3D3");
        _program.addUniform("uMVMatrix");
        _program.addUniform("uMVPMatrix");
        _program.addUniform("uNormalMatrix");
        _program.addUniform("uTexture");
        _texture = Texture("../../asset/Textures/superpacgommetest.jpg");
    }
};

#endif //IMACGL_SUPERPACGOMME_HPP
