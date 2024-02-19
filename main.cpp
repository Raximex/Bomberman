//#include "src/Graphics/Graphics.h"
#include "main.h"
#include "src/Graphics/Graphics.h"
#include "src/game/Carte.cpp"

using namespace sf;

void inputHandlerJoueur(Event event, RenderWindow &window, Sprite &spriteJoueur);
void loadJoueur(Texture &JoueurT, Sprite &JoueurS);

enum Dir{Up,Down,Right,Left};
Vector2i anim(1,Down);



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
                    0,1,2,3,4,5,6,7,8,9,10,
                    11,12,13,14,15,16,17,18,19,20,21
                    ,22,23,24,25,26,27,28,
                    29,30,31,32,33,34,35,36,37,38,39,40,
                    41,42,43,44,45,46,47,48,49,50,51,52,53,54
                    ,55,56,57,58,59,60,61,62,63,64,65,66,67,68,
                    69,70,71,72,73,74,75,76,77,
                    78,79,80,81,82,83,84,85,86,87,88,89,90,91,
                    92,93,94,95,96,97,98,99,100

            };

    graphicsMenu.loadMenu(textureMenu,spriteMenu);
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Up))//Gestion du menu
                mainMenu.MoveUp();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                mainMenu.MoveDown();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                if (mainMenu.MainMenuPressed() == 0) {
                    graphicsJoueur.loadJoueur(textureJoueur, spriteJoueur);
                    inputHandlerJoueur(event,window,spriteJoueur);
                    /*  if(!map.load("assets/Stage1.png", sf::Vector2u(22, 22),level, 11, 10))
                          return -1;*/
                }

            }
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
    {    anim.y = Right;
    spriteJoueur.setPosition(position+sf::Vector2f (1,0));}

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {    anim.y = Down;
        spriteJoueur.setPosition(position+sf::Vector2f (0,-1));}

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {   anim.y = Down;
        spriteJoueur.setPosition(position+sf::Vector2f (0,1));}

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {  anim.y = Down;
        spriteJoueur.setPosition(position+sf::Vector2f (-1,0));}
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){}
        //lancer la bombe sur la carte
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::End)){}
        //ouvrir la page de paramètres
}


