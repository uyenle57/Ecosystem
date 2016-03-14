//
//  SmallFish.cpp
//  cppUyen2
//
//  Created by Uyen Le on 13/03/2016.
//
//

#include "SmallFish.hpp"


SmallFish::SmallFish(float fishPosX, float fishPosY, float fishPosZ) : Animals(fishPosX, fishPosY, fishPosZ) {
    
    mPosition.set(fishPosX, fishPosY, fishPosZ);
    bodyColor.set(0,0,255);
    
    mDamping = 0.01f;
    mMaxForce = 5.0;
    mMaxSpeed = 5;
    mDistance = 50;
    mCount = 0;
    
    bIsClose = true;
}

SmallFish::~SmallFish() {
    
}

//------------------------------------------------------------------------------------
void SmallFish::draw() {
    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    ofSetColor(bodyColor);
    
    ofDrawCircle(0,0, 5);
    
    ofPopMatrix();
}

//------------------------------------------------------------------------------------
void SmallFish::update() {
    //SmallFish::swim();
    SmallFish::updateForce();
    Animals::returnToScreen();
}

//------------------------------------------------------------------------------------
void SmallFish::swim() {
//    SmallFish::addAttraction();
//    SmallFish::addAlignment();
//    SmallFish::addRepulsion();
}

// FLOCKING BEHAVIOUR
//------------------------------------------------------------------------------------
void SmallFish::updateForce() {
    mVelocity += mAcceleration;
    mVelocity.limit(mMaxSpeed);
    
    mPosition += mVelocity;
    
    resetForce();
}

//------------------------------------------------------------------------------------
void SmallFish::addAttraction(SmallFish &neighbor) {
    
    ofVec3f sum(0,0,0);
    float strength = 0.03;
    
    ofVec3f difference = neighbor.mPosition - mPosition; //Calculate the distance between the current fish and neighour fishes
    float dist = difference.length(); //length() returns magnitude of vector
    ofVec3f diffNormalise = difference;
    diffNormalise.normalize();
    
    if (dist > 0 && dist < mDistance) {    //Check that the current fish is close to neighbor fishes
        sum += diffNormalise;
        mCount++;
    }
    
    if (mCount > 0) {
        mPosition.x += 0.5;
        sum /= float(mCount);
        seekTarget(sum);
        //mAcceleration -= (sum.normalize() * strength);
    }
}

//------------------------------------------------------------------------------------
void SmallFish::addAlignment(SmallFish &neighbor, float radius, float scale) {
    
}

//------------------------------------------------------------------------------------
void SmallFish::addRepulsion(SmallFish &neighbor, float radius, float scale) {

}

//------------------------------------------------------------------------------------
void SmallFish::moveAwayFromMouse(float mousex, float mousey, float radius, float scale) {
    ofVec2f posOfForce;
    posOfForce.set(mousex, mousey);
    
    ofVec2f diff = mPosition - posOfForce;
    float length = diff.length();
    
    if (radius > 0) {
        if (length > radius){
            bIsClose = false;
        }
    }
    if (bIsClose == true) {
        float pct = 1 - (length / radius);  // stronger on the inside
        diff.normalize();
        mAcceleration.x = mAcceleration.x - diff.x * scale * pct;
        mAcceleration.y = mAcceleration.y - diff.y * scale * pct;
    }
}

//------------------------------------------------------------------------------------
void SmallFish::resetForce() {
    mAcceleration.set(0, 0);
}

//------------------------------------------------------------------------------------
void SmallFish::applyForce(ofVec3f force) {
    mAcceleration += force;
}

//------------------------------------------------------------------------------------
void SmallFish::applyDamping() {
    
}

//------------------------------------------------------------------------------------
void SmallFish::seekTarget(ofVec3f target) {
    ofVec3f mDesired = target - mPosition;
    
    mDesired.normalize();
    mDesired * mMaxSpeed;
    
    ofVec3f mSteer = mDesired - mVelocity;
    mSteer.limit(mMaxForce);
    
    applyForce(mSteer);
}

//------------------------------------------------------------------------------------



