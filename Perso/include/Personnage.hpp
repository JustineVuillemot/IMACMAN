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

    /* GETTER */

    glm::vec3 getPos(){
        return _pos;
    }
    glm::vec3 getPosInitiale(){
        return _posInitiale;
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
    void initSphere(GLfloat radius, GLsizei discLat, GLsizei discLong);
    void drawSphere();
private:
    glimac::Sphere _PersoObj;
    VAO p_vao;
    VBO p_vbo;
    glm::vec3 _pos;
    glm::vec3 _posInitiale;
    glm::mat4 _MVMatrix;

    std::string _texturePath;
    Texture _texture;
    //Program _program;

};


#endif //IMACMAN_PERSONNAGE_H
