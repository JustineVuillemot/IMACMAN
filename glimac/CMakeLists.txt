include_directories(include)
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
add_library(glimac ${SRC_FILES} ../IMACMAN/test.cpp ../Prog/src/Buffer.cpp ../Prog/include/Buffer.hpp ../Prog/src/IBO.cpp ../Prog/include/IBO.hpp ../Prog/src/VBO.cpp ../Prog/include/VBO.hpp ../Prog/src/VAO.cpp ../Prog/include/VAO.hpp ../Prog/src/Program.cpp ../Prog/include/Program.hpp ../Prog/src/Texture.cpp ../Prog/include/Texture.hpp ../IMACMAN/TEST_VBOVAOIBO.cpp ../IMACMAN/TEST_Cube.cpp)
