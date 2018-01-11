#ifndef IMACGL_PROG_HPP
#define IMACGL_PROG_HPP

#include <GL/glew.h>
#include <glimac/Program.hpp>
#include <vector>
#include <glimac/glm.hpp>
#include <map>

class Prog{
public:
    Prog() = default;
    Prog(glimac::FilePath &appPath, std::string vs, std::string fs)
            : _appPath(appPath), _fs(fs), _vs(vs) {
        _vs += ".vs.glsl";
        _fs += ".fs.glsl";
        _program = glimac::loadProgram(appPath.dirPath() + "shaders/" + _vs,
                                       appPath.dirPath() + "shaders/" + _fs);
    }

    void addUniform(std::string name){
        _varUnis.insert( std::pair<std::string,GLuint>(name , glGetUniformLocation(_program.getGLId(), name.c_str())));
    }

    void sendUniformMatrix4fv(std::string name, glm::mat4 value){
        glUniformMatrix4fv(_varUnis[name], 1, GL_FALSE, glm::value_ptr(value));
    }

    void sendUniform1i(GLuint value, int num){
        glUniform1i(value, num);
    }


    void use(){
        _program.use();
    }

private:
    glimac::FilePath _appPath;
    std::string _fs;
    std::string _vs;
    glimac::Program _program;
    std::map<std::string, GLuint> _varUnis;
};

#endif //IMACGL_PROG_HPP
