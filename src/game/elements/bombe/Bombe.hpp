//
// Created by raximex on 28/01/24.
//

#ifndef BOMBERMAN_BOMBE_H
#define BOMBERMAN_BOMBE_H

#include "../element.hpp"

class Personnage; 

class Bombe : public Element
{
private :
    int degats = 1;
    int porteAttaque = 1;
    int delaiExplosion = 3; //TODO utiliser heure depart, heure fin pour calcul    
    Personnage & proprietaire;
public : 
    Bombe() = delete ; 
    Bombe( Personnage& proprietaire);
    void poser(sf::RenderWindow &window);
    void exploser();
    void ajoutPowerUp(); //TODO: ajouter un powerup en param
};



#endif //BOMBERMAN_BOMBE_H
