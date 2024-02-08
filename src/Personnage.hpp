//
// Created by raximex on 28/01/24.
//

#ifndef BOMBERMAN_PERSONNAGE_H
#define BOMBERMAN_PERSONNAGE_H

#include <iostream>

using namespace std;
using namespace sf;

class Personnage {
 
    private : 
       string nom;
       Vector2i position();      
        
    public : 
        void move(Vector2i newPosition);
         

        Vector2f getPosition(){
            return this->position;
        }

        Personnage();
        

};
 

#endif //BOMBERMAN_PERSONNAGE_H
