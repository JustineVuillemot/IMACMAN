//
// Created by Alexian on 16/12/2017.
//

#ifndef IMACMAN_JEU_H
#define IMACMAN_JEU_H

#include <cstdlib>
#include <vector>
#include "Cube.hpp"
#include "Personnage.hpp"
#include "Objet.hpp"


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

        for(i=0; i < _nbrSub; ++i) {
            for (j=0; j < _nbrSub; ++j) {
                _cubes.push_back(new Cube(glm::vec3(i*_widthCase, -1*_heightCase, j*_widthCase), glm::vec3((i+1)*_widthCase, 0, (j+1)*_widthCase)));
            }
        }
        int taille = _cubes.size();
        //Creation of the Object in the surface - Séparer de création tableau car : Amélioration : mettre des murs à la place des cubes
        for(i=0; i < _nbrSub; ++i) {
            for (j = 0; j < _nbrSub; ++j) {
                //position : i*widthCase / heightCase / j*widthCase;
                switch (_plateau[i][j]) {
                    case 0:
                        _cubes.push_back(new Cube(glm::vec3(i*_widthCase, 0, j*_widthCase), glm::vec3((i+1)*_widthCase, _heightCase, (j+1)*_widthCase)));
                        break;

                        /*case 1:
                            _personnages.push_back(new Pacman());
                            break;

                        case 2:
                            _objets.push_back(new PacGomme());
                            break;

                        case 3:
                            _objets.push_back(new Bonus());
                            break;

                        case 4:
                            _personnages.push_back(new Fantome());
                            break;

                        case 5:
                            _objets.push_back(new Bonus());
                            break;*/

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
    }

    void freeJeu(){
        int i;
        for(i=0; i < _personnages.size() ; ++i){
            delete _personnages[i];
            _personnages[i] = nullptr;
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

    void draw() {
        int i;
        /*for(i=0; _personnages.size(); ++i){
            _personnages[i].draw();
        }
        for(i=0; _objets.size(); ++i){
            _objets[i].draw();
        }*/
        for(i=0; i < _cubes.size(); ++i){
            _cubes[i]->draw();
        }
    }

    //Variables
    int _plateau[10][10];

private:
    std::vector<Cube*> _cubes;
    std::vector<Personnage*> _personnages;
    std::vector<Objet*> _objets;
    int _nbrSub;
    int _score;
    float _widthCase;
    float _heightCase;
};


#endif //IMACMAN_JEU_H
