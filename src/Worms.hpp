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
    //virtual ~Worms(); //only called when eaten by Animals
    
    void draw(), swim(), movement(), update();
    
    float posx, posy, posz;
    
    float r = 8;
    
    float rotateAngle;
    ofVec3f rotateAmount;
    
private:
    
};

#endif /* Worms_hpp */