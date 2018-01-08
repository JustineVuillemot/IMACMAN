include_directories(include)
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
add_library(Perso ${SRC_FILES} src/FantomeShadow.cpp include/FantomeShadow.hpp src/FantomeSpeedy.cpp include/FantomeSpeedy.hpp src/FantomeBashful.cpp include/FantomeBashful.hpp src/FantomePokey.cpp include/FantomePokey.hpp)
