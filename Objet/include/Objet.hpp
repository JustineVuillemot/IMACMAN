//
// Created by Alexian on 16/12/2017.
//

#include <glm/glm.hpp>
#include <VBO.hpp>
#include <VAO.hpp>
#include <glimac/Sphere.hpp>
#include <Texture.hpp>

#ifndef IMACMAN_OBJET_H
#define IMACMAN_OBJET_H


class Objet {
public:
    Objet() : _obj(1, 30, 30){}
    Objet(glm::vec3 pos, float radius) : _obj(radius, 30, 30){
        _position = pos;
        _etat = 0;
        _nbrPoint = 5;
    }

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
    glm::mat4 getViewMatrix(glm::mat4 viewMat = glm::mat4(1)){
        return glm::translate(viewMat, _position);
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
    void draw();
    void remplirBuffers(){
        o_vbo.remplirBuffer(_obj.getVertexArray());
        o_vao.remplirBuffer(_obj.getVertexArray(), &o_vbo);
    }

protected:
    glimac::Sphere _obj;
    VAO o_vao;
    VBO o_vbo;
    int _nbrPoint;
    glm::vec3 _position;
    int _etat;

    std::string _texturePath;
    Texture _texture;
    //Program _program;
};


#endif //IMACMAN_OBJET_H
