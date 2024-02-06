//
// Created by raximex on 02/02/24.
//
#ifndef BOMBERMAN_MAINMENU_H
#define BOMBERMAN_MAINMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

#define Max_main_menu 4

class MainMenu {
public:
    Text mainMenu[Max_main_menu];
    MainMenu(float width, float height);
    void draw(RenderWindow& window);
    void MoveUp();
    void MoveDown();
    void setMainMenuSelected(int n);
    int MainMenuPressed(){
        return MainMenuSelected;
    }
    ~MainMenu();
private:
    int MainMenuSelected;
    Font font;
};


#endif //BOMBERMAN_MAINMENU_H
