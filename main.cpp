//#include "src/Graphics/Graphics.h"
#include "main.h"

using namespace sf;

void inputHandlerJoueur(Event event, RenderWindow &window, Sprite &spriteJoueur);
void loadJoueur(Texture &JoueurT, Sprite &JoueurS);

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "BOMBERMAN", sf::Style::Default, settings);
    sf::Texture textureJoueur;
    sf::Sprite spriteJoueur;
    loadJoueur(textureJoueur,spriteJoueur);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            inputHandlerJoueur(event, window, spriteJoueur);
        }


        window.clear();
        window.draw(spriteJoueur);
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
}

void loadJoueur(Texture &JoueurT, Sprite &JoueurS)
{
    if (JoueurT.loadFromFile("assets/SpriteBomberman1.png")) {
        std::cout << "Image chargée" << std::endl;
        JoueurS.setTexture(JoueurT);
        JoueurS.setTextureRect(sf::IntRect(55, 0, 18, 28));
    } else {
        std::cout << "Image non chargée" << std::endl;
    }
}