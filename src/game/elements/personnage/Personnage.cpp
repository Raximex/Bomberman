//
// Created by raximex on 28/01/24.
//

#include "Personnage.hpp"


Personnage::Personnage(apparence apparence) : skin(apparence), bombe(*this), anim(1,Down)
{
   
    if(skin == apparence::titi){
        texture.loadFromFile("C:/Users/cedri/Documents/GitHub/Bomberman/assets/perso1.png");
        sprite.setTexture(texture);
        nom = titi;
        setPosition(100,200);  
    } 
    destructible = true;
    traversable = false;
  
}

Bombe& Personnage::getBombe()
{
    return bombe;
}

