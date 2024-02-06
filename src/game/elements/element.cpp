#include "element.hpp"
#include <iostream>


Element::Element(){

}

int Element::loadElement(std::string fichier){
     if (texture.loadFromFile(fichier)) {
        std::cout << "Image\""<< fichier << "\"chargée" << std::endl;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 65, 16, 26));
        return 1;
    } else {
        std::cout << "Image "<< fichier << " non chargée" << std::endl;
        return 0;
    }
}

void Element::setPosition(int x, int y)
{
    sprite.setPosition(x,y);
    
}

void Element::setPosition(sf::Vector2f nouvellePosition)
{
    sprite.setPosition(nouvellePosition);
  
}
sf::Vector2f Element::getPosition(){
    return sprite.getPosition();
}

sf::Sprite& Element::getSprite() {
    return sprite;
}