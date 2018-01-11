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
#include "SuperPacGomme.hpp"
#include "Bonus.hpp"
#include "FantomePokey.hpp"
#include "FantomeBashful.hpp"
#include "FantomeShadow.hpp"
#include "FantomeSpeedy.hpp"


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

    float getTimeTouch() const;
    float getTimePacman() const;

    /* SETTER */
    void set_nbrSub(int _nbrSub);

    void setTimeTouch(float time);
    void setTimePacman(float time);

    void setScore(int score){
        _score = score;
    }
    void setWidth(int width){
        _widthCase = width;
    }
    void setHeight(int height){
        _heightCase = height;
    }

    void addElement(glimac::FilePath &appPath){
        int i =0;
        int j =0;

        for(i=0; i < _nbrSub; ++i) {
            for (j=0; j < _nbrSub; ++j) {
                _cubes.push_back(new Cube(glm::vec3(j*_widthCase - _nbrSub/2.0, -1*_heightCase/2.0, i*_widthCase - _nbrSub/2.0), glm::vec3((i+1)*_widthCase - _nbrSub/2.0, 0, (j+1)*_widthCase - _nbrSub/2.0), appPath));
            }
        }
        int taille = _cubes.size();
        //Creation of the Object in the surface - Séparer de création tableau car : Amélioration : mettre des murs à la place des cubes
        for(i=0; i < _nbrSub; ++i) {
            for (j = 0; j < _nbrSub; ++j) {
                //position : i*widthCase / heightCase / j*widthCase;
                //std::cout << _plateau[i][j] << std::endl;
                switch (_plateau[i*_nbrSub + j]) {

                    case 0:
                        _cubes.push_back(new Cube(glm::vec3(j*_widthCase - _nbrSub/2.0 , 0,i*_widthCase - _nbrSub/2.0), glm::vec3((j+1)*_widthCase - _nbrSub/2.0, _heightCase,(i+1)*_widthCase - _nbrSub/2.0 ), appPath));

                        break;

                    case 1:
                        _pacman.push_back(new Pacman(glm::vec3(j*_widthCase+_widthCase/2.f - _nbrSub/2.0, _heightCase/2.f,i*_widthCase+_widthCase/2.f - _nbrSub/2.0 ), 0.3, appPath));
                        break;

                    case 2:
                        _objets.push_back(new PacGomme(glm::vec3(j*_widthCase+_widthCase/2.f - _nbrSub/2.0, _heightCase/2.f,i*_widthCase+_widthCase/2.f - _nbrSub/2.0), 0.1, appPath));
                        break;

                    case 3:
                        _objets.push_back(new SuperPacGomme(glm::vec3(j*_widthCase+_widthCase/2.f - _nbrSub/2.0, _heightCase/2.f,i*_widthCase+_widthCase/2.f - _nbrSub/2.0 ), 0.2, appPath));
                        break;

                    case 4:
                        _personnages.push_back(new Fantome(glm::vec3(j*_widthCase+_widthCase/2.f - _nbrSub/2.0, _heightCase/2.f,i*_widthCase+_widthCase/2.f - _nbrSub/2.0 ), 0.3, appPath));
                        break;

                    case 5:
                        _objets.push_back(new Bonus(glm::vec3(j*_widthCase+_widthCase/2.f - _nbrSub/2.0, _heightCase/2.f,i*_widthCase+_widthCase/2.f - _nbrSub/2.0), 0.15, appPath));
                        break;

                    case 6:
                        _personnages.push_back(new FantomePokey(glm::vec3(j*_widthCase+_widthCase/2.f - _nbrSub/2.0, _heightCase/2.f,i*_widthCase+_widthCase/2.f - _nbrSub/2.0 ), 0.3, appPath));
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

    void draw(glm::mat4 modelViewMat, glm::mat4 normalMat, glm::mat4 mvProjMat, glm::mat4 camViewMat) {
        int i;
        for(i=0; i < _cubes.size(); ++i){
            _cubes[i]->_program.use();
            _cubes[i]->_program.sendUniform1i(_cubes[i]->_texture._texture, 0);
            modelViewMat = camViewMat;
            _cubes[i]->_program.sendUniformMatrix4fv("uMVMatrix", modelViewMat);
            _cubes[i]->_program.sendUniformMatrix4fv("uNormalMatrix", normalMat);
            _cubes[i]->_program.sendUniformMatrix4fv("uMVPMatrix", mvProjMat*modelViewMat);
            _cubes[i]->_texture.bind();
            _cubes[i]->draw();
            _cubes[i]->_texture.debind();
        }
        for(i=0; i < _personnages.size(); ++i){
            _personnages[i]->_program.use();
            modelViewMat = _personnages[i]->getViewMatrix(camViewMat);
            _personnages[i]->_program.sendUniformMatrix4fv("uMVMatrix", modelViewMat);
            _personnages[i]->_program.sendUniformMatrix4fv("uNormalMatrix", normalMat);
            _personnages[i]->_program.sendUniformMatrix4fv("uMVPMatrix", mvProjMat*modelViewMat);
            _personnages[i]->draw();
        }
        for(i=0; i < _pacman.size(); ++i){
            _pacman[i]->_program.use();
            _pacman[i]->_program.sendUniform1i(_pacman[i]->_texture._texture, 0);
            modelViewMat = _pacman[i]->getViewMatrix(camViewMat);
            modelViewMat = glm::rotate(modelViewMat, _pacman[i]->getRotation(), glm::vec3(0, 1, 0));
            _pacman[i]->_program.sendUniformMatrix4fv("uMVMatrix", modelViewMat);
            _pacman[i]->_program.sendUniformMatrix4fv("uNormalMatrix", normalMat);
            _pacman[i]->_program.sendUniformMatrix4fv("uMVPMatrix", mvProjMat*modelViewMat);
            _pacman[i]->_texture.bind();
            _pacman[i]->draw();
            _pacman[i]->_texture.debind();
        }
        for(i=0; i < _objets.size(); ++i){
            _objets[i]->_program.use();
            _objets[i]->_program.sendUniform1i(_objets[i]->_texture._texture, 0);
            modelViewMat = _objets[i]->getViewMatrix(camViewMat);
            _objets[i]->_program.sendUniformMatrix4fv("uMVMatrix", modelViewMat);
            _objets[i]->_program.sendUniformMatrix4fv("uNormalMatrix", normalMat);
            _objets[i]->_program.sendUniformMatrix4fv("uMVPMatrix", mvProjMat*modelViewMat);
            _objets[i]->_texture.bind();
            _objets[i]->draw();
            _objets[i]->_texture.debind();
        }
    }

    int collisionManager(glm::vec3 direction);
    int collisionManager(glm::vec3 direction, float time);
    void retourPerso();
    void deplacementFantome(float time);
    glm::vec3 testNewtDir(int index, const glm::vec3 dir);

    //Variables
    //Pacman _pacman;
    std::vector<Pacman*> _pacman;
private:
    std::vector<int> _plateau;
    std::vector<Cube*> _cubes;
    std::vector<Personnage*> _personnages;

    std::vector<Objet*> _objets;
    int _nbrSub;
    int _score;
    float _widthCase;
    float _heightCase;
    float _timeTouch; //To know when pacman was touch for the last time
    float _timePacman; //To check when pacman touch a super pac gomme for the last time
};


#endif //IMACMAN_JEU_H
