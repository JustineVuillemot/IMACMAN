#ifndef IMACGL_TEXTURE_HPP
#define IMACGL_TEXTURE_HPP

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glimac/Image.hpp>
#include <SDL/SDL.h>


class Texture {
public:
    Texture() = default;
    Texture(std::string path){
        try{
            load(path);
        }
        catch(const std::string &s){
            std::cout << "Erreur : " << s << std::endl;
        }
    }

    Texture(const SDL_Surface &surface){
        GLenum texture_format;
        if (surface.format->Rmask == 0x000000ff)
            texture_format = GL_RGBA;
        else
            texture_format = GL_BGRA;

        glGenTextures(1, &_texture);
        bind();
        glTexImage2D(GL_TEXTURE_2D, 0, 4, surface.w, surface.h, 0, texture_format, GL_UNSIGNED_BYTE, surface.pixels);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        debind();
    }

    void load(std::string path){
        std::unique_ptr<glimac::Image> img = glimac::loadImage(path);
        if(img == nullptr){
            throw std::string("Probleme chargement de la texture");
        }
        glGenTextures(1, &_texture);
        bind();
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img->getWidth(), img->getHeight(), 0, GL_RGBA, GL_FLOAT, img->getPixels());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        debind();
    }

    void bind(GLenum textureUnit = GL_TEXTURE0){
        _texture_unit = textureUnit;
        glActiveTexture(_texture_unit);
        glBindTexture(GL_TEXTURE_2D, _texture);
    }

    void debind(){
        glActiveTexture(_texture_unit);
        glBindTexture(GL_TEXTURE_2D, 0);
    }



    void free();

    GLuint _texture;
private:
    GLenum _texture_unit;

};


#endif //IMACGL_TEXTURE_HPP
