//
// Created by raximex on 28/01/24.
//

#include "Bombe.hpp"

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
    setPosition(proprietaire.getPosition().x + 40, proprietaire.getPosition().y + 100); //TODO: Il faut ensuite set l'objet sur la carte pour qu'il y reste
    window.draw(sprite);
 
}