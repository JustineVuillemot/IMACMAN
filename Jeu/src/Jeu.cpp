//
// Created by Alexian on 16/12/2017.
//


#include "Jeu.hpp"
#include <sstream>


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
