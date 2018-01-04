//
// Created by Alexian on 16/12/2017.
//

#ifndef IMACMAN_JEU_H
#define IMACMAN_JEU_H

#include <cstdlib>
#include <vector>
#include <string>
#include "Cube.hpp"
#include "Personnage.hpp"
#include "Pacman.hpp"
#include "Fantome.hpp"
#include "Objet.hpp"
#include "PacGomme.hpp"
#include "Bonus.hpp"


class Jeu {

public:
    Jeu() = default;
    Jeu(std::string filepath, float widthCase, float heightCase);

    /* GETTER */
    std::vector<Personnage *> getPersonnages(){
        return _personnages;
    }
    std::vector<Objet *> getObjets(){
        return _objets;
    }

    int getScore(){
        return _score;
    }
    int getWidth(){
        return _widthCase;
    }
    int getHeight(){
        return _heightCase;
    }
    int get_nbrSub() const;


    /* SETTER */
    void set_nbrSub(int _nbrSub);

    void setScore(int score){
        _score = score;
    }
    void setWidth(int width){
        _widthCase = width;
    }
    void setHeight(int height){
        _heightCase = height;
    }

    void addElement(){
        int i =0;
        int j =0;

        /*for(i=0; i < _nbrSub; ++i) {
            for (j=0; j < _nbrSub; ++j) {
                _cubes.push_back(new Cube(glm::vec3(i*_widthCase, -1*_heightCase, j*_widthCase), glm::vec3((i+1)*_widthCase, 0, (j+1)*_widthCase)));
            }
        }*/
        int taille = _cubes.size();
        //Creation of the Object in the surface - Séparer de création tableau car : Amélioration : mettre des murs à la place des cubes
        for(i=0; i < _nbrSub; ++i) {
            for (j = 0; j < _nbrSub; ++j) {
                //position : i*widthCase / heightCase / j*widthCase;
                //std::cout << _plateau[i][j] << std::endl;
                switch (_plateau[i][j]) {

                    case 0:
                        _cubes.push_back(new Cube(glm::vec3(j*_widthCase - _nbrSub/2.0 , 0,i*_widthCase - _nbrSub/2.0), glm::vec3((j+1)*_widthCase - _nbrSub/2.0, _heightCase,(i+1)*_widthCase - _nbrSub/2.0 )));

                        break;

                    case 1:
                        _pacman.push_back(new Pacman(glm::vec3(j*_widthCase+_widthCase/2.f - _nbrSub/2.0, _heightCase/2.f,i*_widthCase+_widthCase/2.f - _nbrSub/2.0 ), 0.3));
                        break;

                    case 2:
                        _objets.push_back(new PacGomme(glm::vec3(j*_widthCase+_widthCase/2.f - _nbrSub/2.0, _heightCase/2.f,i*_widthCase+_widthCase/2.f - _nbrSub/2.0), 0.1));
                        break;

                    case 3:
                        _objets.push_back(new Bonus(glm::vec3(j*_widthCase+_widthCase/2.f - _nbrSub/2.0, _heightCase/2.f,i*_widthCase+_widthCase/2.f - _nbrSub/2.0 ), 0.1));
                        break;

                    case 4:
                        _personnages.push_back(new Fantome(glm::vec3(j*_widthCase+_widthCase/2.f - _nbrSub/2.0, _heightCase/2.f,i*_widthCase+_widthCase/2.f - _nbrSub/2.0 ), 0.3));
                        break;

                    case 5:
                        _objets.push_back(new Bonus(glm::vec3(j*_widthCase+_widthCase/2.f, _heightCase/2.f,i*_widthCase+_widthCase/2.f ), 0.1));
                        break;

                    default:
                        break;
                }
            }
        }
    }

    void remplirBuffer(){
        int i;
        for(i=0; i<_cubes.size(); ++i){
            _cubes[i]->remplirBuffers();
        }
        for(i=0; i<_pacman.size(); ++i){
            _pacman[i]->remplirBuffers();
        }
        for(i=0; i<_personnages.size(); ++i){
            _personnages[i]->remplirBuffers();
        }
        for(i=0; i<_objets.size(); ++i){
            _objets[i]->remplirBuffers();
        }
    }

    void freeJeu(){
        int i;
        for(i=0; i < _personnages.size() ; ++i){
            delete _personnages[i];
            _personnages[i] = nullptr;
        }
        for(i=0; i < _pacman.size() ; ++i){
            delete _pacman[i];
            _pacman[i] = nullptr;
        }
        for(i=0; i < _objets.size() ; ++i){
            delete _objets[i];
            _objets[i] = nullptr;
        }
        for(i=0; i < _cubes.size() ; ++i){
            delete _cubes[i];
            _cubes[i] = nullptr;
        }
    }

    void draw(GLuint uMVMatrix, glm::mat4 modelViewMat, GLuint uNormalMatrix, glm::mat4 normalMat, GLuint uMVPMatrix, glm::mat4 mvProjMat, glm::mat4 camViewMat) {
        int i;
        for(i=0; i < _cubes.size(); ++i){
            _cubes[i]->draw();
        }
        for(i=0; i < _personnages.size(); ++i){
            modelViewMat = _personnages[i]->getViewMatrix(camViewMat);
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(modelViewMat));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(normalMat));
            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(mvProjMat*modelViewMat));
            _personnages[i]->draw();
        }
        for(i=0; i < _pacman.size(); ++i){
            modelViewMat = _pacman[i]->getViewMatrix(camViewMat);
            modelViewMat = glm::rotate(modelViewMat, _pacman[i]->getRotation(), glm::vec3(0, 1, 0));
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(modelViewMat));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(normalMat));
            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(mvProjMat*modelViewMat));
            _pacman[i]->draw();
        }
        for(i=0; i < _objets.size(); ++i){
            modelViewMat = _objets[i]->getViewMatrix(camViewMat);
            glUniformMatrix4fv(uMVMatrix, 1, GL_FALSE, glm::value_ptr(modelViewMat));
            glUniformMatrix4fv(uNormalMatrix, 1, GL_FALSE, glm::value_ptr(normalMat));
            glUniformMatrix4fv(uMVPMatrix, 1, GL_FALSE, glm::value_ptr(mvProjMat*modelViewMat));
            _objets[i]->draw();
        }
    }

    int collisionManager(glm::vec3 direction);
    //Variables
    //Pacman _pacman;
    std::vector<Pacman*> _pacman;
private:
    int _plateau[10][10];
    std::vector<Cube*> _cubes;
    std::vector<Personnage*> _personnages;

    std::vector<Objet*> _objets;
    int _nbrSub;
    int _score;
    float _widthCase;
    float _heightCase;
};


#endif //IMACMAN_JEU_H
