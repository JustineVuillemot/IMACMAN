//
// Created by Alexian on 16/12/2017.
//

#include <Cube.hpp>
#include "../include/Personnage.hpp"

void Personnage::deplacement(glm::vec3 dist){
    setPos(getPos() + dist);
}

void Personnage::draw() {
    p_vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, _PersoObj.getVertexCount());
    p_vao.debind();
}

void Personnage::changeDirection(){
    _direction = glm::vec3(-1*(_direction.z), 0, _direction.x);
    this->rotatePerso(int(this->getAngleOrientation()+90)%360);
}

int Personnage::collisionPerso(Personnage &Perso2, glm::vec3 direction){
    glm::vec3 posPerso2 = Perso2.getPos(); //contour de la sphère
    if(direction.x != 0){
        if(_pos.y < posPerso2.y + 0.2 && _pos.y > posPerso2.y - 0.2
           && _pos.z < posPerso2.z + 0.2 && _pos.z > posPerso2.z - 0.2
           && _pos.x + direction.x < posPerso2.x + 0.5 && _pos.x + direction.x > posPerso2.x - 0.5 ){
            return 1;
        }
    }
    else if (direction.y != 0){
        if(_pos.x < posPerso2.x + 0.2 && _pos.x > posPerso2.x - 0.2
           && _pos.z < posPerso2.z + 0.2 && _pos.z > posPerso2.z - 0.2
           && _pos.y + direction.y < posPerso2.y + 0.5 && _pos.y + direction.y > posPerso2.y - 0.5){
            return 1;
        }
    }
    else{
        if(_pos.y < posPerso2.y + 0.2 && _pos.y > posPerso2.y - 0.2
           && _pos.x < posPerso2.x + 0.2 && _pos.x > posPerso2.x - 0.2
           && _pos.z + direction.z < posPerso2.z + 0.5 && _pos.z + direction.z > posPerso2.z - 0.5){
            return 1;
        }
    }
    return 0;
}

int Personnage::collisionObjet(Objet &objet, glm::vec3 direction){
    glm::vec3 posObjet = objet.getPosition(); //contour de la sphère
    if(direction.x != 0){
        if(_pos.y < posObjet.y + 0.2 && _pos.y > posObjet.y - 0.2
           && _pos.z < posObjet.z + 0.2 && _pos.z > posObjet.z - 0.2
           && _pos.x + direction.x < posObjet.x + 0.3 && _pos.x + direction.x > posObjet.x - 0.3 ){
            return 1;
        }
    }
    else if (direction.y != 0){
        if(_pos.x < posObjet.x + 0.2 && _pos.x > posObjet.x - 0.2
           && _pos.z < posObjet.z + 0.2 && _pos.z > posObjet.z - 0.2
           && _pos.y + direction.y < posObjet.y + 0.3 && _pos.y + direction.y > posObjet.y - 0.3){
            return 1;
        }
    }
    else{
        if(_pos.y < posObjet.y + 0.2 && _pos.y > posObjet.y - 0.2
           && _pos.x < posObjet.x + 0.2 && _pos.x > posObjet.x - 0.2
           && _pos.z + direction.z < posObjet.z + 0.3 && _pos.z + direction.z > posObjet.z - 0.3){
            return 1;
        }
    }
    return 0;
}

int Personnage::collisionCube(Cube &cube, glm::vec3 direction){
    glm::vec3 posCube = cube.getPosition();
    if(direction.x != 0 && direction.x >= 0){ //MOVE RIGHT
        if(_pos.y < posCube.y && _pos.y > posCube.y - 1.4
           && _pos.z > posCube.z - 0.495 && _pos.z  < posCube.z + 1.495
           && _pos.x + 0.01 > posCube.x - 0.5 && _pos.x + 0.01 < posCube.x +1){
            return 1;
        }
    }
    if(direction.x != 0 && direction.x < 0){ //MOVE LEFT
        if(_pos.y < posCube.y && _pos.y > posCube.y - 1.4
           && _pos.z > posCube.z - 0.495 && _pos.z  < posCube.z + 1.495
           && _pos.x - 0.01 < posCube.x + 1.5 && _pos.x - 0.01 > posCube.x){
            return 1;
        }
    }
    if(direction.z != 0 && direction.z >= 0){ //MOVE DOWN
        if(_pos.y < posCube.y && _pos.y > posCube.y - 1.4
           && _pos.x > posCube.x - 0.495 && _pos.x < posCube.x + 1.495
           && _pos.z + 0.01 > posCube.z - 0.495 && _pos.z + 0.01 < posCube.z +1){
            return 1;
        }
    }
    if(direction.z != 0 && direction.z < 0){ //MOVE UP
        if(_pos.y < posCube.y && _pos.y > posCube.y - 1.4
           && _pos.x > posCube.x - 0.495 && _pos.x  < posCube.x + 1.495
           && _pos.z - 0.01 < posCube.z + 1.5 && _pos.z - 0.01 > posCube.z){
            return 1;
        }
    }
    return 0;
}

void Personnage::rotatePerso(float newAngle) {
    float angleRotation = getAngleOrientation() - 360.f + newAngle;
    setAngleOrientation(newAngle);
    setRotation(angleRotation);
}