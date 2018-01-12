
#ifndef IMACGL_MENU_HPP
#define IMACGL_MENU_HPP

#include "UI.hpp"

class Menu{
public:
    Menu(){};
    Menu(std::string fontPath);
    ~Menu() = default;

    void generateVertices();
    void generateIndexs();
    void remplirBuffers(){
        m_vbo.remplirBuffer(_vertexVec);
        m_ibo.remplirBuffer(_indexVect);
        m_vao.remplirBuffer(_vertexVec, &m_vbo, &m_ibo);
    }

    void drawRect();
    void draw();

private:
    UI _reTryGame;
    UI _saveGame;
    UI _loadGame;
    std::vector<ShapeVertex> _vertexVec;
    std::vector<uint32_t> _indexVect;
    VBO m_vbo;
    IBO m_ibo;
    VAO m_vao;
};

#endif //IMACGL_MENU_HPP
