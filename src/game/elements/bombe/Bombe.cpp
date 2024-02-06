//
// Created by raximex on 28/01/24.
//

#include "Bombe.hpp"
#include <iostream>
#include "../personnage/Personnage.hpp"

Bombe::Bombe( Personnage& proprietaire) : proprietaire(proprietaire)
{
    if(!loadElement("C:/Users/cedri/OneDrive/Documents/GitHub/Bomberman/assets/Bomberman(1).png")){
        return;
    }
    destructible = false;
    traversable = true;

    
}

void Bombe::poser(sf::RenderWindow &window)
{
    setPosition(proprietaire.getPosition().x, proprietaire.getPosition().y); //TODO: Il faut ensuite set l'objet sur la carte pour qu'il y reste
    window.draw(sprite);
 
}