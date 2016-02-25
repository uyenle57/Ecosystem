//
//  Organism.cpp
//  cppUyen2
//
//  Created by Uyen Le on 16/02/2016.
//
//

#include "Organism.hpp"

Organism::Organism() {
    mPosition.set(0, 0, 0);
    mVelocity.set(0, 0, 0);
    mAcceleration.set(0, 0, 0);
    
    mTheta = 0;
    mMaxForce = 0.05;
    mMaxSpeed = 2;
}

//--------------------------------------------------------------
void Organism::update() {
    mVelocity = mVelocity + mAcceleration;
    mVelocity.limit(mMaxSpeed);
    
    mPosition = mPosition + mVelocity;
    
    mAcceleration = mAcceleration * 0; //reset acceleration to 0
}

//--------------------------------------------------------------
void Organism::applyForce(ofVec3f force) {
    mAcceleration = mAcceleration + force; //force accumulation
}

//--------------------------------------------------------------
void Organism::seek(ofVec3f target) {
    ofVec3f mDesired = target - mPosition;  //A vector pointing from the location to the target
    
    mDesired.normalize();  // Normalize and scale to maximum speed
    mDesired * mMaxSpeed;
    
    ofVec3f mSteer = mDesired - mVelocity;
    mSteer.limit(mMaxForce);  //Limit to maximum steering force
    
    applyForce(mSteer);
}
