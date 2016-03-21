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
    
    mHealth = 100; //Starting health of 100%
    
    hungryColor.set(255,190,10);  //orange
    starvingColor.set(255,0,0);  //red

}

Animals::~Animals() {
    cout << "Animals killed" << endl;
}

void Animals::operator=(const Animals &A) {
    mPosition = A.mPosition;    //return the position
}

//--------------------------------------------------------------
void Animals::returnToScreen() {
    if(mPosition.x < -screenBorder)  mPosition.x = ofGetWidth() + screenBorder;
    if(mPosition.y < -screenBorder)  mPosition.y = ofGetHeight() + screenBorder;
    if(mPosition.x > ofGetWidth()+screenBorder)  mPosition.x = -screenBorder;
    if(mPosition.y > ofGetHeight()+screenBorder)  mPosition.y = -screenBorder;
}

// HOW TO MOVE
//--------------------------------------------------------------
void Animals::applyForce(ofVec3f force) {
    mAcceleration += force;     //force accumulation
}
//--------------------------------------------------------------
void Animals::resetForce() {
    mAcceleration.set(0,0,0);   //reset acceleration
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
ofVec3f Animals::seekFish (ofVec3f targetFish) {
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

// HOW TO REPRODUCE
//------------------------------------------------------------------------

// HOW TO CHANGE BODY COLOUR TO SHOW HEALTH STATUS
//------------------------------------------------------------------------
ofColor Animals::changeColour(ofColor healthyCol) {
   
    ofColor bodyColor;
    
    if (mHealth > 50 && mHealth <= 100) {   //Healthy: 50-100%
        bodyColor = healthyCol;
    }
    else if (mHealth > 25 && mHealth <= 50) {   //Hungry: 25-50%
        bodyColor = hungryColor;  //turns orange
    }
    else if (mHealth > 0 && mHealth <= 25) {    //Starving: 0-20%
        bodyColor = starvingColor; //turns red
    }
    else if (mHealth <= 0) {
        //call destructor
        bodyColor.set(0);
    }
    
    return bodyColor;
}

// DECREASE HEALTH
//------------------------------------------------------------------------
void Animals::decreaseHealth() {
    mHealth -= 0.05;
    //cout << mHealth << endl;
}

// HOW TO DIE
//------------------------------------------------------------------------
bool Animals::bIsDead() {
    if (mHealth < 0.0) return true;
    else return false;
}
