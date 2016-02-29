//
//  Organism.hpp
//  cppUyen2
//
//  Created by Uyen Le on 16/02/2016.
//
//  Abstract base class Organism - won't be instantiated


#ifndef Organism_hpp
#define Organism_hpp

#include <stdio.h>
#include "ofMain.h"


//contains DNA, location, velocity, acceleration, behaviours (swim, jump, mate)
//no lifespan

class Organism {
    
public:
    Organism(float x, float y, float z);
    
private:
    
protected:
    //virtual ~Organism();
    
    ofVec3f mPosition, mVelocity, mAcceleration;
    
    //Variables
    float mTheta, mMaxForce, mMaxSpeed;
    float mPosx, mPosy, mPosz; //position variables
    
    //Pure virtual functions - must be overriden in derived classes
    virtual void draw() = 0;
    virtual void swim() = 0;
    virtual void movement() = 0;
    
    void organism_Update(); //contains all other void functions
    void organism_returnToScreen();
    void applyForce(ofVec3f force), seekTarget(ofVec3f target), resetForce();
    
    bool isDead(); //call Destructor or return true/false??
    
};

#endif /* Organism_hpp */


