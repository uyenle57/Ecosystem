//
//  Worms.hpp
//  cppUyen2
//
//  Created by Uyen Le on 21/02/2016.
//
//  Derived Organism 1
//  Worms wander around + Oscillate horizontally.


#ifndef Worms_hpp
#define Worms_hpp

#include <stdio.h>
#include "Organism.hpp"


class Worms: public Organism {
    
public:
    Worms(float wormPosX, float wormPosY, float wormPosZ);
    //virtual ~Worms();
    
    void eat(), swim(), movement(), returnToScreen(), draw();
    void update();
    
    float posx, posy, posz;

    float r = 8; //an arbitrary variable
    
private:
    
};

#endif /* Worms_hpp */