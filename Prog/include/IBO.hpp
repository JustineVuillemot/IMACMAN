#ifndef IMACGL_IBO_HPP
#define IMACGL_IBO_HPP

class IBO : public Buffer{
public:
    IBO();
    ~IBO();

    void bind();
    void debind();

    template <typename type>
    void remplirBuffer(std::vector<type> &vect){
        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, vect.size() * sizeof(type), vect.data(), GL_STATIC_DRAW);
        debind();
    };
};


#endif //IMACGL_IBO_HPP
