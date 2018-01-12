//
// Created by Alexian on 08/01/2018.
//

#ifndef IMACGL_FANTOMEPOKEY_HPP
#define IMACGL_FANTOMEPOKEY_HPP


#include "Fantome.hpp"

class FantomePokey : public Fantome{
public:
    FantomePokey (glm::vec3 pos, float radius, glimac::FilePath &appPath){
        _PersoObj = glimac::Sphere(radius, 30, 30);
        _pos = _posInitiale = pos;
        _etat = 0;
        _randDirection = 1.f;
        _direction = glm::vec3(0,0,-0.3);

        _program = Prog(appPath, "3D", "tex3D3");
        _program.addUniform("uMVMatrix");
        _program.addUniform("uMVPMatrix");
        _program.addUniform("uNormalMatrix");
        _program.addUniform("uTexture");
        _texture = Texture("../../asset/Textures/fantome1.jpg");
        _texture2 = Texture("../../asset/Textures/fantome2.jpg");

    }

    void deplacement(glm::vec3 dist) override;

};


#endif //IMACGL_FANTOMEPOKEY_HPP
