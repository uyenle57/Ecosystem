//
//  Animals.cpp
//  cppUyen2
//
//  Created by Uyen Le on 26/02/2016.
//
//  Base class Animals

#include "Animals.hpp"


DNA::DNA() {
    for(int i=0; i < 1; i++) {
        genes.push_back(i);
    }
    for(int i=0; i < genes.size(); i++) {  //Make a random DNA
        genes[i] = ofRandom(1); //random floating value between 0 and 1
    }
}
//Copy the DNA
DNA::DNA(const DNA &dna) {
    std::vector<float> newgenes;
    newgenes = dna.genes;
}

void DNA::mutate(float prob) {
    for (int i=0; i < genes.size(); i++) {
        if (ofRandom(1) < prob) //Mutation based on probability
            genes[i] = ofRandom(1); //pick a new random character
    }
}

// ANIMALS ----------------------------------------------------------------
Animals::Animals(float x, float y, float z): mPosx(x), mPosy(y), mPosz(z){
    mPosition.set(0, 0, 0);
    mVelocity.set(0, 0, 0);
    mAcceleration.set(0, 0, 0);
    
    mLifespan = 100;
    
    //DNA determines:
    //Genotype: speed, weight of force (bigger => slower)
    //          longer they survive => higher chance of reproduction
    //Phenotype: bodysize, eyesize
}

//------------------------------------------------------------------------
void Animals::returnToScreen() {
    if(mPosition.x < -mBorder)  mPosition.x = ofGetWidth() + mBorder;
    if(mPosition.y < -mBorder)  mPosition.y = ofGetHeight() + mBorder;
    if(mPosition.x > ofGetWidth()+mBorder)  mPosition.x = -mBorder;
    if(mPosition.y > ofGetHeight()+mBorder)  mPosition.y = -mBorder;
}

//------------------------------------------------------------------------
void Animals::update() {
    mVelocity += mAcceleration;
    mVelocity.limit(mMaxSpeed);
    
    mPosition += mVelocity;
    
    resetForce();
}

//--------------------------------------------------------------
void Animals::applyForce(ofVec3f force) {
    mAcceleration += force; //force accumulation
}

//--------------------------------------------------------------
void Animals::resetForce() {
    mAcceleration.set(0,0,0);   //reset acceleration to 0
}

//--------------------------------------------------------------
void Animals::seekTarget(ofVec3f target) {
    ofVec3f mDesired = target - mPosition;  //A vector pointing from the location to the target
    
    mDesired.normalize();  // Normalize and scale to maximum speed
    mDesired * mMaxSpeed;
    
    ofVec3f mSteer = mDesired - mVelocity;
    mSteer.limit(mMaxForce);  //Limit to maximum steering force
    
    applyForce(mSteer);
}

//------------------------------------------------------------------------
void Animals::swim() {
    float radius = 20;
    float distance = 80;
    wanderAngle += ofRandom(-0.1, 0.1);
    
    ofVec3f wanderAround = mVelocity;
    wanderAround.normalize();
    wanderAround *= distance;
    wanderAround += mPosition;
    
    ofVec3f wanderOffset(radius*(cos(wanderAngle)*0.5), radius*(sin(wanderAngle)*0.5) );
    ofVec3f target = wanderAround + wanderOffset;
    
    seekTarget(target);
}

//------------------------------------------------------------------------
bool Animals::bIsDead() {
    if (mLifespan < 0.0) return true;
    else return false;
}
