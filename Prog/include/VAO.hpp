#define GLEW_STATIC
#ifndef IMACGL_VAO_HPP
#define IMACGL_VAO_HPP

#include "VBO.hpp"
#include "IBO.hpp"

class VAO : public Buffer {
public:
    VAO();
    ~VAO();

    void bind();
    void debind();

    template <typename type>
    void remplirBuffer(std::vector<type> &vect, VBO *vbo, IBO *ibo = nullptr){
        bind();
        if(ibo){
            ibo->bind();
        }
        const GLuint VERTEX_ATTR_POSITION = 0;
        const GLuint VERTEX_ATTR_NORMAL = 1;
        const GLuint VERTEX_ATTR_TEXTURE = 2;
        glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
        glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
        glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);
        vbo->bind();
        glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE,
                              sizeof(type), (const GLvoid*) offsetof(type, position));
        glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE,
                              sizeof(type), (const GLvoid*) offsetof(type, normal));
        glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE,
                              sizeof(type), (const GLvoid*) offsetof(type, texCoords));
        vbo->debind();
        debind();
    };
};


#endif //IMACGL_VAO_HPP
