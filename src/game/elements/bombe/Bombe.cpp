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

    if(!loadSpriteFlammes("C:/Users/cedri/OneDrive/Documents/GitHub/Bomberman/assets/Bomberman(1).png")){
        return;
    }
  
    flammes(spriteFlamme,porteAttaque* 4);
    
    destructible = false;
    traversable = true;
    
    
}

void Bombe::poser(sf::RenderWindow &window)
{
    setPosition(proprietaire.getPosition().x, proprietaire.getPosition().y); //TODO: Il faut ensuite set l'objet sur la carte pour qu'il y reste
    window.draw(sprite);
 
}

void Bombe::exploser(){
    for(int i = 0; i < porteAttaque * 4; i++){
      
    }

}

int Bombe::loadSpriteFlammes(std::string fichier){
    if (textureFlamme.loadFromFile(fichier)) {
        std::cout << "Image\""<< fichier << "\"chargée" << std::endl;
        spriteFlamme.setTexture(texture);
        spriteFlamme.setTextureRect(sf::IntRect(0, 65, 16, 26));
        return 1;
    } else {
        std::cout << "Image "<< fichier << " non chargée" << std::endl;
        return 0;
    }
}