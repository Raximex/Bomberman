//
// Created by raximex on 28/01/24.
//

#ifndef BOMBERMAN_CARTE_H
#define BOMBERMAN_CARTE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
void draw(sf::RenderTarget& target, sf::RenderStates states);
bool load(const std::string& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);


#endif //BOMBERMAN_CARTE_H
