//
// Created by Alexian on 16/12/2017.
//

#include "../include/Personnage.hpp"

void Personnage::deplacement() {

}

void Personnage::draw() {
    p_vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, _PersoObj.getVertexCount());
    p_vao.debind();
}