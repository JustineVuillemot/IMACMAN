//
// Created by Alexian on 08/01/2018.
//

#include "FantomePokey.hpp"

void FantomePokey::deplacement(glm::vec3 dist){
    setPos(getPos()+dist);
    if(rand()%2000 == 0){
        setRandDirection(getRandDirection()*-1.f);
    }
    setDirection(getDirection()*getRandDirection());
}