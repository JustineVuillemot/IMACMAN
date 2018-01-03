//
// Created by Alexian on 16/12/2017.
//

#include "../include/Objet.hpp"

void Objet::draw() {
    o_vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, _obj.getVertexCount());
    o_vao.debind();
}