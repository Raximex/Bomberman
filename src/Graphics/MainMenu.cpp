//
// Created by raximex on 02/02/24.
//

#include "MainMenu.h"

MainMenu::MainMenu(float width, float height) {
    if (font.loadFromFile("assets/Znikoslsvginot8-GOB3y.ttf"))
        cout << "Pas d'image ici";

    //Bouton Rejoindre partie
    mainMenu[0].setFont(font);
    mainMenu[0].setFillColor(Color::White);
    mainMenu[0].setString("Rejoindre une Partie");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(400, 200);
    //Bouton Créer une partie
    mainMenu[1].setFont(font);
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Créer une partie");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(400, 300);
    //Bouton Score
    mainMenu[2].setFont(font);
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("Rejoindre une Partie");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setPosition(400, 400);
    //Bouton Paramètres
    mainMenu[3].setFont(font);
    mainMenu[3].setFillColor(Color::White);
    mainMenu[3].setString("Rejoindre une Partie");
    mainMenu[3].setCharacterSize(70);
    mainMenu[3].setPosition(400, 500);

    MainMenuSelected = 0;
}
    MainMenu::~MainMenu(){};

void MainMenu::setMainMenuSelected(int n)
{
    MainMenuSelected=n;
}
    void MainMenu::draw(sf::RenderWindow &window) {
    for(int i=0 ;i<Max_main_menu; i++)
        window.draw(mainMenu[i]);
}

void MainMenu::MoveUp() {
    if(MainMenuSelected - 1 >= -1) {
        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected--;
        if (MainMenuSelected == -1)
            MainMenuSelected = 3;
        mainMenu[MainMenuSelected].setFillColor(Color::Magenta);
    }
}
void MainMenu::MoveDown() {
    if(MainMenuSelected +1 <=Max_main_menu)
    {
        mainMenu[MainMenuSelected].setFillColor(Color::White);
        MainMenuSelected++;
        if(MainMenuSelected==4)
        {
            MainMenuSelected=0;
        }
        mainMenu[MainMenuSelected].setFillColor(Color::Blue);
    }
}




