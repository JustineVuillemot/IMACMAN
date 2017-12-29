//
// Created by Alexian on 16/12/2017.
//

#ifndef IMACMAN_JEU_H
#define IMACMAN_JEU_H

#include <cstdlib>
#include <vector>
#include "Personnage.hpp"
#include "Objet.hpp"

class Jeu {

public:

    /* GETTER */

    std::vector<Personnage> getPersonnages(){
        return _personnages;
    }
    std::vector<Objet> getObjets(){
        return _objets;
    }

    // Ici faire le getter du plateau

    int getScore(){
        return _score;
    }
    int getWidth(){
        return _widthCase;
    }
    int getHeight(){
        return _heightCase;
    }

    /* SETTER */

    void setScore(int score){
        _score = score;
    }
    void setWidth(int width){
        _widthCase = width;
    }
    void setHeight(int height){
        _heightCase = height;
    }

private:
    char _nomDuFichier;
    std::vector<Personnage> _personnages;
    std::vector<Objet> _objets;
    int _plateau; //Il faut faire un tableau de tableau ??
    int _score;
    int _widthCase;
    int _heightCase;


};


#endif //IMACMAN_JEU_H
