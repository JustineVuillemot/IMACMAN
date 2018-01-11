#include <glm/glm.hpp>
#include <VBO.hpp>
#include <VAO.hpp>
#include <glimac/Sphere.hpp>
#include <Texture.hpp>
#include "Prog.hpp"

#ifndef IMACGL_ATMO_HPP
#define IMACGL_ATMO_HPP

class Atmo {
public:
    Atmo() : _obj(1, 30, 30){}
    Atmo(glm::vec3 pos, float radius) : _obj(radius, 30, 30){
        _position = pos;
        _etat = 0;
    }

    Atmo(glm::vec3 pos, float radius, glimac::FilePath &appPath) : _obj(radius, 30, 30){
        _position = pos;
        _etat = 0;
        _program = Prog(appPath, "3D", "tex3D3");
        _program.addUniform("uMVMatrix");
        _program.addUniform("uMVPMatrix");
        _program.addUniform("uNormalMatrix");
        _program.addUniform("uTexture");
        _texture1 = Texture("../../asset/Textures/atmo1.jpg");
        _texture2 = Texture("../../asset/Textures/pacgommetest.jpg");
    }

    /* GETTER */

    glm::vec3 getPosition(){
        return _position;
    }
    int getEtat(){
        return _etat;
    }
    glm::mat4 getViewMatrix(glm::mat4 viewMat = glm::mat4(1)){
        return glm::translate(viewMat, _position);
    }

    /* SETTER */

    void setPosition(glm::vec3 position){
        _position = position;
    }
    void setEtat(int etat){
        _etat = etat;
    }

    /* METHODS */
    void draw();
    void remplirBuffers(){
        o_vbo.remplirBuffer(_obj.getVertexArray());
        o_vao.remplirBuffer(_obj.getVertexArray(), &o_vbo);
    }

    Texture _texture1;
    Texture _texture2;
    Prog _program;
protected:
    glimac::Sphere _obj;
    VAO o_vao;
    VBO o_vbo;
    glm::vec3 _position;
    int _etat; //Si etat = 0 pas de superPacGomme sinon mode SuperPacGomme
};

#endif //IMACGL_ATMO_HPP
