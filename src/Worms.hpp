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
    
    void draw(), swim(), update();
    void addWorm(Organism *o);
    virtual void keyPressed(int key);
    
    float posx, posy, posz;
    float segLength = 2;
    float wanderAngle;
    ofVec3f rotateAmount;
    
    ofColor(bodyColor);
    
protected:
    float wiggle(int m);
    
private:
    
};

#endif /* Worms_hpp */