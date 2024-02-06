//
// Created by raximex on 28/01/24.
//
#include "Graphics.h"
#include <iostream>
Graphics::Graphics(Texture texture, Sprite sprite) {

}
void Graphics::loadJoueur(Texture &texture, Sprite &sprite)
{
    if (texture.loadFromFile("assets/Bomberman(1).png")) {
        std::cout << "Image chargée" << std::endl;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 65, 16, 26));
    } else {
        std::cout << "Image non chargée" << std::endl;
    }
}
void Graphics::loadMenu(Texture &texture, Sprite &sprite)
{
    if(texture.loadFromFile("assets/Menu.png"))
    {
        std::cout << "Image chargée menu" << std::endl;
        sprite.setTexture(texture);
    }else {
        std::cout << "Image non chargée" << std::endl;
    }
}