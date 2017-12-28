//
// Created by Alexian on 16/12/2017.
//

#include "../include/Objet.hpp"

void Objet::initSphere(GLfloat radius, GLsizei discLat, GLsizei discLong) {
    glimac::Sphere testSphere(radius, discLat, discLong);
    _obj =  testSphere;
}

void Objet::drawObj() {
    o_vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, _obj.getVertexCount());
    o_vao.debind();
}