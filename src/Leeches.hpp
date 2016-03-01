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
    //~Leeches();
    
    void draw(), swim(), movement(), update();
    void swim(float swimToX, float swimToY);
    
    float offsetX;
    float offsetY;

private:
    float wiggle(int m);
    ofVec3f mPrevPos;
    
    float catchUpSpeed;
    
    float rotateAngle;

};

#endif /* Leeches_hpp */
