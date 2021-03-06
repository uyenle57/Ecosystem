//
//  Leeches.hpp
//  cppUyen2
//
//  Created by Uyen Le on 21/02/2016.
//
//  Derived Organism 2
//  Leeches inherite from Worms as they have similar movement, but oscillate vertically
//  instead of horizontally. Also they look different.


#ifndef Leeches_hpp
#define Leeches_hpp

#include <stdio.h>
#include "Organism.hpp"

class Leeches: public Organism {
    
public:
    Leeches(float leechPosX, float leechPosY, float leechPosZ);
    
    ~Leeches();
    
    void draw(), swim(), update();
    ofVec3f getPos();
    
private:
    float wiggle(int m);
    float x;
    float wanderAngle;
    
    ofColor(bodyColor);
    
};

#endif /* Leeches_hpp */
