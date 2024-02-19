//#include "src/Graphics/Graphics.h"
<<<<<<<<< Temporary merge branch 1
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

=========
#include "main.h"
#include "src/Graphics/Graphics.h"
#include "src/game/Carte.hpp"

using namespace sf;

void inputHandlerJoueur(Event event, RenderWindow &window, Sprite &spriteJoueur);
void loadJoueur(Texture &JoueurT, Sprite &JoueurS);




int main() {
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(sf::VideoMode(1600, 900), "BOMBERMAN", sf::Style::Default, settings);
    MainMenu mainMenu((float)window.getSize().x, (float)window.getSize().y);
    Texture textureJoueur, textureMenu;
    Sprite spriteMenu, spriteJoueur;
    Graphics graphicsJoueur(textureJoueur,spriteJoueur);
    Graphics graphicsMenu(textureMenu,spriteMenu);
    //graphicsJoueur.loadJoueur(textureJoueur,spriteJoueur);
    graphicsMenu.loadMenu(textureMenu,spriteMenu);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            inputHandlerJoueur(event, window, spriteJoueur);
            if(Keyboard::isKeyPressed(Keyboard::Up))//Gestion du menu
                mainMenu.MoveUp();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                mainMenu.MoveDown();
>>>>>>>>> Temporary merge branch 2
        }


        window.clear();
        window.draw(spriteJoueur);
<<<<<<<<< Temporary merge branch 1
=========
        window.draw(spriteMenu);
        mainMenu.draw(window);//affichage du texte grace a la fonction draw
>>>>>>>>> Temporary merge branch 2
        window.display();
    }
}

void inputHandlerJoueur(Event event, RenderWindow &window, Sprite &spriteJoueur)
{
    if(event.type == sf::Event::Closed){
        window.close();
    }
    sf::Vector2f  position = spriteJoueur.getPosition();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
     spriteJoueur.setPosition(position+sf::Vector2f (1,0));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        spriteJoueur.setPosition(position+sf::Vector2f (0,-1));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        spriteJoueur.setPosition(position+sf::Vector2f (0,1));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        spriteJoueur.setPosition(position+sf::Vector2f (-1,0));
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){}
        //lancer la bombe sur la carte
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::End)){}
        //ouvrir la page de paramètres
}


