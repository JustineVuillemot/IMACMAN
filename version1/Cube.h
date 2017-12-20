//
// Created by Alexian on 16/12/2017.
//

#include <glm/glm.hpp>

#ifndef IMACMAN_CUBE_H
#define IMACMAN_CUBE_H


class Cube {
public:

    /* GETTER */

    std::vector<Point> getVertexVec(){
        return _vertexVec;
    }
    glm::vec3 getPosition(){
        return _position;
    }

    /* SETTER */

    void setPositon(glm::vec3 position){
        _position = position;
    }
private:
    std::vector<Point> _vertexVec;
    glm::vec3 _position;
};


#endif //IMACMAN_CUBE_H
