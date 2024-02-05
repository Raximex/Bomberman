//#include "src/Graphics/Graphics.h"
#include "main.h"

#include "src/game/Carte.hpp"

using namespace sf;

void inputHandlerJoueur(Event event, RenderWindow &window, Sprite &spriteJoueur);
void loadJoueur(Texture &JoueurT, Sprite &JoueurS);
void loadMenu(Texture &menuT, Sprite &menu);



int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1600, 900), "BOMBERMAN", sf::Style::Default, settings);
    MainMenu mainMenu((float)window.getSize().x, (float)window.getSize().y);

    sf::Texture textureJoueur;
    sf::Texture textureMenu;
    sf::Sprite  spriteMenu;
    sf::Sprite spriteJoueur;
    //loadJoueur(textureJoueur,spriteJoueur);
    loadMenu(textureMenu,spriteMenu);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            inputHandlerJoueur(event, window, spriteJoueur);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                mainMenu.MoveUp();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                mainMenu.MoveDown();
        }


        window.clear();
        window.draw(spriteJoueur);
        window.draw(spriteMenu);
        mainMenu.draw(window);
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


void loadJoueur(Texture &JoueurT, Sprite &JoueurS)
{
    if (JoueurT.loadFromFile("assets/Bomberman(1).png")) {
        std::cout << "Image chargée" << std::endl;
        JoueurS.setTexture(JoueurT);
        JoueurS.setTextureRect(sf::IntRect(0, 65, 16, 26));
    } else {
        std::cout << "Image non chargée" << std::endl;
    }
}
void loadMenu(Texture &menuT, Sprite &menu)
{
    if(menuT.loadFromFile("assets/Menu.png"))
    {
        std::cout << "Image chargée menu" << std::endl;
        menu.setTexture(menuT);
    }else {
        std::cout << "Image non chargée" << std::endl;
    }
}