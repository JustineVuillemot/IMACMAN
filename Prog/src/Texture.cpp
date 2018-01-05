#include "Texture.hpp"
#include <iostream>


void Texture::free(){
    glDeleteTextures(1, &_texture);
}