#ifndef __ELEMENT__
#define __ELEMENT__

#include<SFML/Graphics.hpp>

class Element 
{
    protected : 
    bool destructible, traversable;
    sf::Texture texture;
    sf::Sprite sprite; 
    
    public : 
    Element() ; 
    void setPosition(int x, int y );
    void setPosition(sf::Vector2f nouvellePosition);
    void deplacer(sf::Vector2f nouvellePosition);

    sf::Vector2f getPosition();

    int loadElement(std::string); //TODO: Ajouter un rect en param pour gerer les différents sprite
    sf::Sprite&  getSprite();

    

};

#endif