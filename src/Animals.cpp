//
//  Animals.cpp
//  cppUyen2
//
//  Created by Uyen Le on 26/02/2016.
//
//  Base class Animals

#include "Animals.hpp"


Animals::Animals(float x, float y, float z, DNA &dna): mPosx(x), mPosy(y), mPosz(z), dna(&dna) {
    mPosition.set(0, 0, 0);
    mVelocity.set(0, 0, 0);
    mAcceleration.set(0, 0, 0);
    
    mLifespan = 200; //All animals have equal life span value
    
    hungryColor.set(255,190,10);  //orange
    starvingColor.set(255,0,0);  //red
}

Animals::~Animals() {
    
}

// HOW TO MOVE
//------------------------------------------------------------------------
void Animals::returnToScreen() {
    if(mPosition.x < -mBorder)  mPosition.x = ofGetWidth() + mBorder;
    if(mPosition.y < -mBorder)  mPosition.y = ofGetHeight() + mBorder;
    if(mPosition.x > ofGetWidth()+mBorder)  mPosition.x = -mBorder;
    if(mPosition.y > ofGetHeight()+mBorder)  mPosition.y = -mBorder;
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
void Animals::update() {
    mVelocity += mAcceleration;
    mVelocity.limit(mMaxSpeed);
    
    mPosition += mVelocity;
    
    resetForce();
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

//--------------------------------------------------------------
ofVec3f Animals::seekFish(ofVec3f targetFish) {
    ofVec3f mDesired = targetFish - mPosition;  //A vector pointing from the location to the target
    
    mDesired.normalize();  // Normalize and scale to maximum speed
    mDesired * mMaxSpeed;
    ofVec3f mSteer = mDesired - mVelocity;
    mSteer.limit(mMaxForce);  //Limit to maximum steering force
    
    return mSteer;
}

//------------------------------------------------------------------------
void Animals::swim() {
    float radius = 20;
    float distance = 80;
    wanderAngle += ofRandom(-0.05, 0.05);
    
    ofVec3f wanderAround = mVelocity;
    wanderAround.normalize();
    wanderAround *= distance;
    wanderAround += mPosition;
    
    ofVec3f wanderOffset(radius*(cos(wanderAngle)*0.5), radius*(sin(wanderAngle)*0.5) );
    ofVec3f target = wanderAround + wanderOffset;
    
    seekTarget(target);
}

// HOW TO EAT
//void Animals::eat() {
//    
//}

// HOW TO REPRODUCE
//------------------------------------------------------------------------

// HOW TO SHOW HEALTH STATUS THROUGH CHANGING BODY COLOUR
//------------------------------------------------------------------------
ofColor Animals::healthStatus() {
   
    ofColor bodyColor;
    float alpha = 100;
    
    if (mLifespan > 100 && mLifespan <= 200) {
        //healthy color
        //depends on each animal's unique color
    }
    else if (mLifespan > 50 && mLifespan <= 100) {
        bodyColor = hungryColor;  //turns orange
    }
    else if (mLifespan > 0 && mLifespan <= 50) {
      bodyColor = starvingColor; //turns red
    }
    else if (mLifespan <= 0.0) {
        //call destructor
    }
    
    return bodyColor;
}

// HOW TO DIE
//------------------------------------------------------------------------
bool Animals::bIsDead() {
    if (mLifespan < 0.0) return true;
    else return false;
}
