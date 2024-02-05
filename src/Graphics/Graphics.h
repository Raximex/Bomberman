//
// Created by raximex on 28/01/24.
//


#ifndef BOMBERMAN_GRAPHICS_H
#define BOMBERMAN_GRAPHICS_H

#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Graphics {
public:
    Graphics(Texture texture, Sprite sprite);
    void run();
    void loadJoueur(Texture &texture, Sprite &sprite);
    void loadMenu(Texture &texture, Sprite &sprite);

};







#endif //BOMBERMAN_GRAPHICS_H
