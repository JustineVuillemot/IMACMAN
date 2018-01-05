#ifndef IMACGL_PROG_HPP
#define IMACGL_PROG_HPP

#include <glimac/Program.hpp>
#include <vector>
#include <glimac/glm.hpp>
#include <map>

class Prog{
public:
    Prog() = default;
    Prog(glimac::FilePath &appPath, std::string vs, std::string fs);

    void addUniform(std::string name){
        _varUnis.insert( std::pair<std::string,GLuint>(name , glGetUniformLocation(_program.getGLId(), name.c_str())));
    }

    void sendUniformMatrix4fv(std::string name, glm::mat4 value){
        glUniformMatrix4fv(_varUnis[name], 1, GL_FALSE, glm::value_ptr(value));
    }

    void use();

private:
    glimac::FilePath _appPath;
    std::string _fs;
    std::string _vs;
    glimac::Program _program;
    std::map<std::string, GLuint> _varUnis;
};

#endif //IMACGL_PROG_HPP
