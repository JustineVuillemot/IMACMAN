//
// Created by Alexian on 16/12/2017.
//

#include <glm/glm.hpp>
#include <VBO.hpp>
#include <IBO.hpp>
#include <VAO.hpp>

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
private:
    VAO p_vao;
    VBO p_vbo;
    IBO p_ibo;
    glm::vec3 _pos;
    glm::vec3 _posInitiale;

};


#endif //IMACMAN_PERSONNAGE_H
