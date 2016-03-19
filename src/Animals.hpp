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


//The population of each Animal is based on their genetic information (DNA)
//which defines how the animal looks or behaves
//with reference from Nature of Code's Chapter 9
class DNA {
//DNA determines:
//Genotype: speed, weight of force (bigger => slower)
//          longer they survive => higher chance of reproduction
//Phenotype: bodysize, eyesize

public:
    DNA();
    DNA(const DNA &dna);    //Use copy constructor for reproduction

    std::vector <float> genes;

    void mutate(float prob);
};


// ANIMALS ---------------------------------------------------------------
class Animals {

public:
    Animals(float x, float y, float z);
    //virtual ~Animals();
    
    ofVec3f mPosition, mVelocity, mAcceleration;
    ofColor healthyColor, hungryColor, starvingColor;
    
    float mLifespan;    //life timer
    //determine how long it takes for the Animal to start changing color, if it hasn't eaten anything
    float mMaxForce, mMaxSpeed, mSize;
    float mRotateTheta, wanderAngle;
    
    float mPosx, mPosy, mPosz;
    float mBorder = 2;

    //Functions
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void swim() = 0;  //derived classes can override if needed
    
protected:
    DNA dna;
    void reproduce(), eat(), changeColor();
    void applyForce(ofVec3f force);
    void seekTarget(ofVec3f target);
    ofVec3f seekFish(ofVec3f targetFish); //for SmallFish
    void resetForce();
    void returnToScreen();
    
    bool bIsDead();
    
};
#endif /* Animals_hpp */
