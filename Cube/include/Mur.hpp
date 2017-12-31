//
// Created by Alexian on 16/12/2017.
//

#include "Cube.hpp"

#ifndef IMACMAN_MUR_H
#define IMACMAN_MUR_H


class Mur : public Cube {
public:
    Mur(){};
    Mur(const glm::vec3 position, const float width, const float height, const float depth);

    /* GETTER */

    float getEpaisseur(){
        return _depth;
    }
    float getWidth(){
        return _width;
    }
    float getHeight(){
        return _height;
    }

    /* SETTER */

    void setEpaisseur(float epaisseur){
        _depth = epaisseur;
    }
    void setWidth(float taille){
        _width = taille;
    }
    void setHeight(float hauteur){
        _height = hauteur;
    }
private:
    float _depth;
    float _width;
    float _height;
};


#endif //IMACMAN_MUR_H
