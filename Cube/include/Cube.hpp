//
// Created by Alexian on 16/12/2017.
//

#ifndef IMACMAN_CUBE_H
#define IMACMAN_CUBE_H

#include <glm/glm.hpp>
#include <glimac/common.hpp>

using namespace glimac;

class Cube {
public:

    Cube(){};
    Cube(const glm::vec3& lower, const glm::vec3& upper);

    /* GETTER */
    std::vector<ShapeVertex> getVertexVec(){
        return _vertexVec;
    }
    std::vector<uint32_t> getIndexVec(){
        return _indexVec;
    }
    glm::vec3 getPosition(){
        return _position;
    }

    /* SETTER */

    void setPositon(glm::vec3 position){
        _position = position;
    }

private:
    std::vector<ShapeVertex> _vertexVec;
    std::vector<uint32_t> _indexVec;
    glm::vec3 _position;
};


#endif //IMACMAN_CUBE_H
