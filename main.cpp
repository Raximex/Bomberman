//#include "src/Graphics/Graphics.h"
#include <SFML/Graphics.hpp>
#include <iostream>


void deplacer(sf::Sprite & spriteJoueur){

        sf::Vector2f  position = spriteJoueur.getPosition();
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            spriteJoueur.setPosition(position+sf::Vector2f (5,0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            spriteJoueur.setPosition(position+sf::Vector2f (0,-5));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            spriteJoueur.setPosition(position+sf::Vector2f (0,5));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            spriteJoueur.setPosition(position+sf::Vector2f (-5,0));
}

int main()
{   sf::ContextSettings settings;
    settings.antialiasingLevel=8;
    sf::RenderWindow window(sf::VideoMode(800,600),"BOMBERMAN", sf::Style::Default, settings);
    sf::Texture textureJoueur;
    sf::Sprite  spriteJoueur;

    if(textureJoueur.loadFromFile("C:/Users/cedri/OneDrive/Documents/GitHub/Bomberman/assets/SpriteBomberman1.png"))
    {
        std::cout << "Image chargée" << std::endl;
        spriteJoueur.setTexture(textureJoueur);
        spriteJoueur.setTextureRect(sf::IntRect (55,0,18,28));
    }
    else{
        std::cout << "Image non chargée" << std::endl;
    }

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {       if(event.type == sf::Event::Closed){
                window.close();
            }

                deplacer(spriteJoueur);

        }


        window.clear();
        window.draw(spriteJoueur);
        window.display();
    }

}
