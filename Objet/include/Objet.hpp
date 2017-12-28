//
// Created by Alexian on 16/12/2017.
//

#include <glm/glm.hpp>
#include <VBO.hpp>
#include <VAO.hpp>
#include <glimac/Sphere.hpp>
#include <Texture.hpp>
#include <Program.hpp>

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

    /* METHODS */
    void initSphere(GLfloat radius, GLsizei discLat, GLsizei discLong)
    void drawObj();

private:
    glimac::Sphere _obj;
    VAO o_vao;
    VBO o_vbo;
    int _nbrPoint;
    glm::vec3 _position;
    int _etat;

    std::string _texturePath;
    Texture _texture;
    Program _program;
};


#endif //IMACMAN_OBJET_H
