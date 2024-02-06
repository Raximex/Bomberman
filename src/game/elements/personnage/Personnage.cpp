//
// Created by raximex on 28/01/24.
//

#include "Personnage.hpp"


Personnage::Personnage(apparence apparence) : skin(apparence), bombe(*this)
{
   
    if(skin == apparence::titi){
        loadElement("C:/Users/cedri/OneDrive/Documents/GitHub/Bomberman/assets/Bomberman(1).png");
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

