//
// Created by raximex on 15/02/24.
//
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;
#ifndef BOMBERMAN_ANIMATION_H
#define BOMBERMAN_ANIMATION_H

using namespace std;
#include <cstdlib>
#include <iostream>
#include <fstream>

class Animation
{
public:
    Animation(void);
    ~Animation(void);

    void Initialize(float x, float y, int FrameX, int FrameY);
    void Update(RenderWindow &Window);
    void Draw(RenderWindow &Window);
    bool getActive();
    void setActive(bool active);

    int getCurrentFrame (int axis);
    void setCurrentFrame (int axis, int value);

    float getPosition (int axis);
    void setPosition (int axis, int value);

    void setImage(Image &tempImage);

    int getFrameWidth(); //largeur
    int getFrameHeight(); //hauteur


private:

    Sprite spriteImage;
    int currentFrameX, currentFrameY;
    float frameCounter, switchFrame;
    float x, y;
    int amountOfFramesX, amountOfFramesY; // ex pour la video : 4,4
    bool active;

    Clock Clock;


};

#endif //BOMBERMAN_ANIMATION_H
