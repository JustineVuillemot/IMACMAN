//
// Created by Alexian on 16/12/2017.
//

#include "../include/Personnage.hpp"

void Personnage::deplacement() {

}

void Personnage::initSphere(GLfloat radius, GLsizei discLat, GLsizei discLong) {
    glimac::Sphere testSphere(radius, discLat, discLong);
    _PersoObj =  testSphere;
}

void Personnage::drawSphere() {
    p_vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, _PersoObj.getVertexCount());
    p_vao.debind();
}