#include "../include/Atmo.hpp"

void Atmo::draw() {
    o_vao.bind();
    glDrawArrays(GL_TRIANGLES, 0, _obj.getVertexCount());
    o_vao.debind();
}