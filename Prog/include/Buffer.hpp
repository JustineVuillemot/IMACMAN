#define GLEW_STATIC

#ifndef IMACGL_BUFFER_HPP
#define IMACGL_BUFFER_HPP

#include <GL/glew.h>
#include <glimac/common.hpp>
#include <iostream>
#include <vector>

class Buffer {
public :
    Buffer() = default;

    void setId(GLuint id);

    GLuint getId(GLuint id);

    virtual void bind(){};
    virtual void debind(){};

    template <typename type>
    void remplirBuffer(std::vector<type> vect){};

protected:
    GLuint m_ID{};

};


#endif //IMACGL_BUFFER_HPP
