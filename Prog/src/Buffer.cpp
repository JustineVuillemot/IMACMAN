#include <GL/glew.h>
#include <Buffer.hpp>

void Buffer::setId(GLuint id){
    m_ID = id;
}

GLuint Buffer::getId(GLuint id){
    return m_ID;
}
