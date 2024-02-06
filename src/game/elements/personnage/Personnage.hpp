//
// Created by raximex on 28/01/24.
//

#ifndef __BOMBERMAN_PERSONNAGE__
#define __BOMBERMAN_PERSONNAGE__

#include "../element.hpp"
#include "apparence.hpp"
#include "../bombe/Bombe.hpp"


class Personnage : public Element
{
private : 
    std::string nom;
    apparence skin; 
    int quantiteBombe = 2;
    int bouclier = 0;
    int viesRestantes = 3;

    Bombe bombe;

public : 
    Personnage() = delete;
    Personnage(apparence apparence); //TODO: définir init pos au chargement de la map
    Bombe& getBombe();

};


#endif //BOMBERMAN_PERSONNAGE_H
