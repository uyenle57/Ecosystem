//
//  Organism.hpp
//  cppUyen2
//
//  Created by Uyen Le on 16/02/2016.
//
// Abstract base class Organism - won't be instantiated


#ifndef Organism_hpp
#define Organism_hpp

#include <stdio.h>
#include "ofMain.h"


class Organism {
    
    //contains DNA, location, velocity, acceleration, behaviours (swim, jump, mate)
    //probability of reproduction
    //reproduction rate
    //no lifespan
    
public:
    Organism();

private:

protected:
    ofVec3f mPosition, mVelocity, mAcceleration;
    //ofVec3f newPosition, newVelocity, newAcceleration;
    float mTheta, mMaxForce, mMaxSpeed, mLifeSpan;
    
    //Pure virtual functions - must be overriden in derived classes
    virtual void draw() = 0;
    virtual void swim() = 0;
    //virtual void movement() = 0;
    //virtual void mate() = 0;
    
    void update();
    void applyForce(ofVec3f force), seek(ofVec3f target);
    
};
#endif /* Organism_hpp */
