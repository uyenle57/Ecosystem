//
//  Animals.hpp
//  cppUyen2
//
//  Created by Uyen Le on 26/02/2016.
//
//  Base class Animals
//  Derived animals: frogs, flock of small fish, big fish

//  Animals eat Organisms and reproduce. Longer they survive the more likely they'll reproduce.
//  They don't bump into each other (collision detection).
//  Change colour if healthy/hungry/starving.
//  Die if run out of food.
//  If all Animals die, Organisms will take over the Pond.


#ifndef Animals_hpp
#define Animals_hpp

#include <stdio.h>
#include "ofMain.h"
#include "DNA.hpp"


class Animals {

public:
    Animals(float x, float y, float z, DNA &dna);
    
    virtual ~Animals();
    
    void operator=(const Animals &A);
    
    
    ofVec3f mPosition, mVelocity, mAcceleration;
    
    ofColor healthyColor, hungryColor, starvingColor;
    
    float mHealth;
    float mMaxForce, mMaxSpeed, mSize;
    float mRotateTheta, wanderAngle;
    
    float birthRate;
    float mutateRate;
    
    float mPosx, mPosy, mPosz;
    float screenBorder = 2;

    //Functions
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void swim() = 0;
    virtual void eat() = 0;
    
protected:
    
    DNA *dna;
    //DNA parentGene;

    //Animals *reproduce(Animals &partner, float prob);
    
    ofColor changeColour(ofColor healthyCol);
    
    void applyForce(ofVec3f force);
    void seekTarget(ofVec3f target);
    ofVec3f seekFish(ofVec3f targetFish); //for SmallFish
    void resetForce();
    void returnToScreen();
    
    void decreaseHealth();
    
    bool bIsDead();
    
};
#endif /* Animals_hpp */
