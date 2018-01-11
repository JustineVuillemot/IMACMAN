//
// Created by Alexian on 16/12/2017.
//

#include "Personnage.hpp"

#ifndef IMACMAN_PACMAN_H
#define IMACMAN_PACMAN_H


class Pacman : public Personnage {
public:
    Pacman(){}
    Pacman (glm::vec3 pos, float radius){
        _pos = _posInitiale = pos;
        _PersoObj = glimac::Sphere(radius, 30, 30);
        _vie = 3;
        _etat = 0;
    }

    Pacman (glm::vec3 pos, float radius, glimac::FilePath &appPath){
        _pos = _posInitiale = pos;
        _PersoObj = glimac::Sphere(radius, 30, 30);
        _vie = 3;
        _etat = 0;

        _program = Prog(appPath, "3D", "tex3D3");
        _program.addUniform("uMVMatrix");
        _program.addUniform("uMVPMatrix");
        _program.addUniform("uNormalMatrix");
        _program.addUniform("uTexture");
        _texture = Texture("../../asset/Textures/pacmantest.jpg");
    }

    /* GETTER */

    int getVie(){
        return _vie;
    }

    int getEtat() const;

    /* SETTER */

    void setVie(int vie){
        _vie = vie;
    }

    void setEtat(int _etat);

    /* METHODS */

    void moveLeft(float distance);
    void moveUp(float distance);

    Texture _texture;
private:
    int _vie;
    int _etat; //Etat = 0, Pacman peut mourir, sinon il peut tuer les fantômes

};


#endif //IMACMAN_PACMAN_H
