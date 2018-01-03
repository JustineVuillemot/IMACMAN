//
// Created by Alexian on 16/12/2017.
//

#include <glm/glm.hpp>
#include <VBO.hpp>
#include <VAO.hpp>
#include <glimac/Sphere.hpp>
#include <Texture.hpp>

#ifndef IMACMAN_PERSONNAGE_H
#define IMACMAN_PERSONNAGE_H


class Personnage {
public:
    Personnage() : _PersoObj(1, 30, 30){}
    Personnage (glm::vec3 pos, float radius) : _PersoObj(radius, 30, 30){
        _pos = _posInitiale = pos;
    }

    /* GETTER */

    glm::vec3 getPos(){
        return _pos;
    }
    glm::vec3 getPosInitiale(){
        return _posInitiale;
    }
    glm::mat4 getViewMatrix(glm::mat4 viewMat = glm::mat4(1)){
        return glm::translate(viewMat, _pos);
    }

    /* SETTER */

    void setPos(glm::vec3 pos){
        _pos = pos;
    }
    void setPosInitiale(glm::vec3 posIni){
        _posInitiale = posIni;
    }

    /* METHODS */
    void deplacement();
    void draw();

    void remplirBuffers(){
        p_vbo.remplirBuffer(_PersoObj.getVertexArray());
        p_vao.remplirBuffer(_PersoObj.getVertexArray(), &p_vbo);
    }

protected:
    glimac::Sphere _PersoObj;
    VAO p_vao;
    VBO p_vbo;
    glm::vec3 _pos;
    glm::vec3 _posInitiale;

    std::string _texturePath;
    Texture _texture;
    //Program _program;

};


#endif //IMACMAN_PERSONNAGE_H
