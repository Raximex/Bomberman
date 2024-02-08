//#include "src/Graphics/Graphics.h"
#include "main.h"
#include "src/Graphics/Graphics.h"
#include "src/game/Carte.cpp"

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
    Carte map;
    const int level[] =
            {
                    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                    0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
                    1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
                    0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
                    0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
                    2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
                    0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
            };

    if(!map.load("assets/grass.png", sf::Vector2u(32, 32), level, 16, 8))
        return -1;
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
        }


        window.clear();
        window.draw(spriteJoueur);
        window.draw(spriteMenu);
        window.draw(map);
        mainMenu.draw(window);//affichage du texte grace a la fonction draw
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


