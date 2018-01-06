//
// Created by Alexian on 16/12/2017.
//


#include "Jeu.hpp"
#include <sstream>
#include <iostream>
#include <cmath>


Jeu::Jeu(std::string filepath, float widthCase, float heightCase){
    //Read the file
    std::ifstream m_read;
    m_read.open(filepath);

    std::string line;
    std::string res = "";
    if(m_read.is_open()){
        while( std::getline (m_read, line) ){
            res += line;
        }
    }
    else{
        throw std::string("The filepath is incorrect !");
    }
    m_read.close();

    //Fill the variables

    _score = 0;
    _widthCase = widthCase;
    _heightCase = heightCase;

    //Creation of the game
    std::string temp;
    std::istringstream iss(res);
    std::getline(iss, temp, ';');
    _nbrSub = std::stoi(temp);


    //Creation of the ground
    int i;
    int j;


    //fill plateau
    for(i=0; i < _nbrSub; ++i) {
        for (j = 0; j < _nbrSub; ++j) {
            std::getline(iss, temp, ';');
            _plateau[i][j] = stoi(temp);
        }
    }
}


int Jeu::get_nbrSub() const {
    return _nbrSub;
}

void Jeu::set_nbrSub(int _nbrSub) {
    Jeu::_nbrSub = _nbrSub;
}


int Jeu::collisionManager(glm::vec3 direction){
    int i;
    for(i=0; i < _personnages.size(); ++i){
        if(_pacman[0]->collisionPerso(*_personnages[i], direction) == 1){
            return 1;
        };
    }
    for(i=0; i < _objets.size(); ++i){
        if(_pacman[0]->collisionObjet(*_objets[i], direction) != 0){
            _objets[i]->setEtat(0);
            _score += 10;
            return 2;
        }
    }
    for(i=0; i < _cubes.size(); ++i){
        if(_pacman[0]->collisionCube(*_cubes[i], direction) != 0){
            return 3;
        }
    }
    return 0;
}

glm::vec3 Jeu::testNewtDir(int index, const glm::vec3 dir){
    int collision = 0;
    glm::vec3 newDir = glm::vec3(fabs(dir.z), 0, -fabs(dir.x));

    //std::cout << fabs(dir.z) << std::endl;

    for(int i=0; i<_cubes.size(); i++){
        if(_personnages[index]->collisionCube(*_cubes[i], newDir)){
            collision = 1;
        }
    }

    if(!collision){
        return newDir;
    }

    return -newDir;
}

void Jeu::deplacementFantome(float time){
    int collision = 0;
    int nbFantome = (time/3)+1; //+1 to be >0

    if(nbFantome > _personnages.size()){
        nbFantome = _personnages.size();
    }

    //std::cout << nbFantome << std::endl;


    for(int j=0; j<nbFantome; j++){
        collision = 0;

        for(int i=0; i<_cubes.size(); i++){
            if(_personnages[j]->collisionCube(*_cubes[i], _personnages[j]->getDirection())){
                collision = 1;
            }
        }

        _personnages[j]->deplacement(_personnages[j]->getDirection()*glm::vec3(0.005/0.3, 0, 0.005/0.3));

        if(collision){
            //std::cout <<  _personnages[j]->getDirection() << std::endl;
            _personnages[j]->setDirection(testNewtDir(j, _personnages[j]->getDirection()));
        }
    }

}