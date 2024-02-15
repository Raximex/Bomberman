//#include "src/Graphics/Graphics.h"
#include "main.h"
#include "src/Graphics/Graphics.h"
#include "src/game/Carte.hpp"

using namespace sf;

void inputHandlerJoueur(Event event, RenderWindow &window, Personnage& perso);
void loadJoueur(Texture &JoueurT, Sprite &JoueurS);




int main() {
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(sf::VideoMode(1600, 900), "BOMBERMAN", sf::Style::Default, settings);
    
    Personnage perso1(titi);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) window.close();

            inputHandlerJoueur(event,window,perso1);
            
        }


        window.clear();
        window.draw(perso1.getSprite());
       // window.draw(perso1.getBombe().getSprite());
        window.display();
    }
}

void inputHandlerJoueur(Event event, RenderWindow &window, Personnage &perso)
{
    if(event.type == sf::Event::Closed){
        window.close();
    }
    sf::Vector2f  position = perso.getPosition();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
     perso.deplacer(sf::Vector2f (1,0));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        perso.deplacer(sf::Vector2f (0,-1));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        perso.deplacer(sf::Vector2f (0,1));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        perso.getSprite().move(sf::Vector2f (-1,0));

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    std::thread poser([&perso, &window](){
        perso.getBombe().poser(window);
    }) ;

    poser.join();
   
    }
    
        //lancer la bombe sur la carte
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::End)){}
        //ouvrir la page de paramètres
}


