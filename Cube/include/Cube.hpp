//
// Created by Alexian on 16/12/2017.
//

#ifndef IMACMAN_CUBE_H
#define IMACMAN_CUBE_H

#include <vector>
#include "VBO.hpp"
#include "VAO.hpp"
#include "IBO.hpp"

using namespace glimac;

class Cube {
public:

    Cube(){};
    Cube(const glm::vec3 &lower,const glm::vec3 &upper);

    ~Cube() = default;

    void remplirBuffers(){
        c_vbo.remplirBuffer(_vertexVec);
        c_ibo.remplirBuffer(_indexVec);
        c_vao.remplirBuffer(_vertexVec, &c_vbo, &c_ibo);

    }

    void generateVertices(const glm::vec3 &lower, const glm::vec3 &upper);
    void generateIndexs();
    void draw();

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

    void print(){
        int i;
        for(i=0; i< _vertexVec.size() ; ++i){
            std::cout << _vertexVec[i].position << std::endl;
        }
        for(i=0; i< _indexVec.size() ; ++i){
            std::cout << _indexVec[i] << std::endl;
        }
    }

protected:
    std::vector<ShapeVertex> _vertexVec;
    std::vector<uint32_t> _indexVec;
    glm::vec3 _position;
    VBO c_vbo;
    IBO c_ibo;
    VAO c_vao;
};


#endif //IMACMAN_CUBE_H
