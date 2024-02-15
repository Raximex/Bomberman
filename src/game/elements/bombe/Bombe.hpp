//
// Created by raximex on 28/01/24.
//

#ifndef BOMBERMAN_BOMBE_H
#define BOMBERMAN_BOMBE_H

#include "../element.hpp"
#include <thread>
class Personnage; //! forward declaration, évite problème d'inclusion

class Bombe : public Element
{
private :
    int degats = 1;
    int porteAttaque = 1;
    int delaiExplosion = 3; //TODO utiliser heure depart, heure fin pour calcul    
    Personnage & proprietaire;
    sf::Texture textureFlamme;
    sf::Sprite spriteFlamme; 
    sf::VertexArray flammes(sf::Sprite, int);
    sf::Texture textureBombe;
    sf::Sprite sprtieBombe; 
    
public : 
    Bombe() = delete ; 
    Bombe( Personnage& proprietaire);
    void poser(sf::RenderWindow &window);
   // void Bombe::exploser(sf::RenderWindow &window);
    void ajoutPowerUp(); //TODO: ajouter un powerup en param
    int loadSpriteFlammes(std::string);
    int loadBombe(std::string);

};



#endif //BOMBERMAN_BOMBE_H
