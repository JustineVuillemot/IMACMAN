
#ifndef IMACGL_VBO_HPP
#define IMACGL_VBO_HPP
#include "Buffer.hpp"

class VBO : public Buffer {
public:
    VBO();
    ~VBO();

    void bind();
    void debind();

    template <typename type>
    void remplirBuffer(std::vector<type> &vect){
        bind();
        glBufferData(GL_ARRAY_BUFFER, vect.size()*sizeof(type), vect.data(), GL_STATIC_DRAW);
        debind();
    };
};


#endif //IMACGL_VBO_HPP
