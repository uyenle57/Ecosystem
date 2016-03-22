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
    
private:
    
public:
    Organism(float x, float y, float z);
    
    virtual ~Organism();
        
    ofVec3f mPosition, mVelocity, mAcceleration;
    
    //Variables
    float mMaxForce, mMaxSpeed, mRotateTheta;
    float mPosx, mPosy, mPosz; //position variables
    float mSize;
    float mBorder = 2;
    
    ofColor bodyColor;
    
    bool isAlive();
    bool bAlive;
    
    //Pure virtual functions
    virtual void draw() = 0;
    virtual void swim() = 0;
    virtual void update() = 0;

    virtual ofVec3f getPos() = 0;
   
    
protected:
    
    void swimUpdate();
    void returnToScreen();
    void applyForce(ofVec3f force);
    void seekTarget(ofVec3f target);
    void resetForce();
    
    bool dead = false;
    
};

#endif /* Organism_hpp */


