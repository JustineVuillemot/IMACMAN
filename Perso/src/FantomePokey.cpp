//
// Created by Alexian on 08/01/2018.
//

#include "FantomePokey.hpp"

void FantomePokey::deplacement(glm::vec3 dist){
    setPos(getPos()+ glm::vec3(dist.x, 0.f, 0.f));
    setPos(getPos()+ glm::vec3(0.f, 0.f, dist.z));
    if(rand()%3000 == 0){
        setRandDirection(getRandDirection()*-1.f);
    }
    setDirection(getDirection()*getRandDirection());
}