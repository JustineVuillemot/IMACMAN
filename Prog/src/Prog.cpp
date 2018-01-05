#include "Prog.hpp"
#include <iostream>

Prog::Prog(glimac::FilePath &appPath, std::string vs, std::string fs)
        : _appPath(appPath), _fs(fs), _vs(vs) {
    _vs += ".vs.glsl";
    _fs += ".fs.glsl";
    _program = glimac::loadProgram(appPath.dirPath() + "shaders/" + _vs,
                                  appPath.dirPath() + "shaders/" + _fs);
}

void Prog::use(){
    _program.use();
}