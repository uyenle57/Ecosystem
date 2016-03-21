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
    
    ~Worms();
    
    void draw(), swim(), update();
    ofVec3f getPos();
    
    void addWorm(Organism *o);
    
    float wanderAngle;
    ofVec3f rotateAmount;
    
protected:
    float wiggle(int m);
    
private:
    ofColor(bodyColor);
    
};

#endif /* Worms_hpp */