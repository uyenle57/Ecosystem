//
//  Organism.cpp
//  cppUyen2
//
//  Created by Uyen Le on 16/02/2016.
//
//

#include "Organism.hpp"
#include "Worms.hpp"

Organism::Organism(float x, float y, float z): mPosx(x), mPosy(y), mPosz(z){
    mPosition.set(0, 0, 0);
    mVelocity.set(0, 0, 0);
    mAcceleration.set(0, 0, 0);
    
    mTheta = 0;
    mMaxForce = 5.0;
    mMaxSpeed = 5;
}

//Organism::~Organism() {
//
//}

//--------------------------------------------------------------
void Organism:: organism_Update() {
    mVelocity += mAcceleration;
    mVelocity.limit(mMaxSpeed);
    
    mPosition += mVelocity;
    
    resetForce();
}

// Wrap borders to make objects return to screen if they go offscreen
//--------------------------------------------------------------
void Organism::organism_returnToScreen() {
    
    if(mPosition.x <= 0)  mPosition.x = 40;
    if(mPosition.y <= 0)  mPosition.y = 40;
    if(mPosition.x >= ofGetWindowWidth()-40)  mPosition.x = ofGetWindowWidth()-40;
    if(mPosition.y >= ofGetWindowHeight()-40)  mPosition.y = ofGetWindowHeight()-40;
}

//--------------------------------------------------------------
void Organism::applyForce(ofVec3f force) {
    mAcceleration += force; //force accumulation
}

//--------------------------------------------------------------
void Organism::resetForce() {
    mAcceleration.set(0,0,0);   //reset acceleration to 0
}

//--------------------------------------------------------------
void Organism::seekTarget(ofVec3f target) {
    ofVec3f mDesired = target - mPosition;  //A vector pointing from the location to the target
    
    mDesired.normalize();  // Normalize and scale to maximum speed
    mDesired * mMaxSpeed;
    
    ofVec3f mSteer = mDesired - mVelocity;
    mSteer.limit(mMaxForce);  //Limit to maximum steering force
    
    applyForce(mSteer);
}

//--------------------------------------------------------------



