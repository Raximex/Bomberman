//
// Created by raximex on 28/01/24.
//

#include "Bombe.hpp"
#include <iostream>
#include "../personnage/Personnage.hpp"

Bombe::Bombe( Personnage& proprietaire) : proprietaire(proprietaire)
{
    if(!loadBombe("C:/Users/cedri/OneDrive/Documents/GitHub/Bomberman/assets/bombes.png")){
        return;
    }

    if(!loadSpriteFlammes("C:/Users/cedri/OneDrive/Documents/GitHub/Bomberman/assets/Bomberman(1).png")){
        return;
    }
  
    
    destructible = false;
    traversable = true;
    
    
}

int Bombe::loadBombe(std::string lien){
    textureBombe.loadFromFile(lien);
    sprtieBombe.setTexture(textureBombe);
    sprtieBombe.setTextureRect(sf::IntRect(0,48,16,16));
    return 1;
}

void Bombe::poser(sf::RenderWindow &window)
{
    setPosition(proprietaire.getPosition().x, proprietaire.getPosition().y); //TODO: Il faut ensuite set l'objet sur la carte pour qu'il y reste
    sf::Clock clock;
    while(clock.getElapsedTime().asSeconds() < 3){
        window.clear();
        window.draw(sprtieBombe);
        window.display();
    }
    clock.restart();
}

//void Bombe::exploser(sf::RenderWindow &window){}

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

