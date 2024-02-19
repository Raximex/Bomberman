//#include "src/Graphics/Graphics.h"
#include "main.h"
#include "src/Graphics/Graphics.h"
#include "src/game/Carte.hpp"

using namespace sf;

void inputHandlerJoueur(Event event, RenderWindow &window, Personnage& perso);
void loadJoueur(Texture &JoueurT, Sprite &JoueurS);
bool updateFPS = false;



int main() {
    ContextSettings settings;
    settings.antialiasingLevel = 8;
    RenderWindow window(sf::VideoMode(1600, 900), "BOMBERMAN", sf::Style::Default, settings);
    
    Personnage perso1(titi);
    sf::Clock clock;
    float fpsCount = 0,
          switchFPS = 100,
          fpsSpeed = 500;

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) window.close();

            inputHandlerJoueur(event,window,perso1);
            
        }
        if(updateFPS)
            fpsCount += fpsSpeed * clock.restart().asSeconds();
        else fpsCount = 0;

        if(fpsCount >= switchFPS){

        perso1.anim.x++;
        if(perso1.anim.x * 22 > perso1.getTexture().getSize().x){
            perso1.anim.x = 0;
        }
        }

        perso1.getSprite().setTextureRect(sf::IntRect(perso1.anim.x * 22, perso1.anim.y * 35,22,35));
        window.clear();
        window.draw(perso1.getSprite());
       // window.draw(perso1.getBombe().getSprite());
        window.display();
        updateFPS = false;
    }
}

void inputHandlerJoueur(Event event, RenderWindow &window, Personnage &perso)
{
    if(event.type == sf::Event::Closed){
        window.close();
    }
    sf::Vector2f  position = perso.getPosition();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        updateFPS = true;
        perso.anim.y = 3; 
        perso.deplacer(sf::Vector2f (1,0));

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        updateFPS = true;
        perso.anim.y = 2;
        perso.deplacer(sf::Vector2f (0,-1));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        updateFPS = false;
        perso.anim.y = 0;
        perso.deplacer(sf::Vector2f (0,1));
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
        updateFPS = true;
        perso.anim.y = 1;
        perso.getSprite().move(sf::Vector2f (-1,0));
    }

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


