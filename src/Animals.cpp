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
    
    birthRate = ofMap(dna.genes[0],0,1,0.01,0.2);
    mutateRate = ofMap(dna.genes[1],0,1,0.15,0.10);
    
    mHealth = 200;
    
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
//Animals *Animals::reproduce(Animals &partner, float prob) {
//    
//    if(ofRandom(1) <= prob) {
//        DNA childGene = parentGene.crossover(partner.parentGene);
//        childGene.mutate(mutateRate);
//        
//        Animals *babyAnimal = new Animals(mPosition.x, mPosition.y, mPosition.z, childGene);
//        
//        return babyAnimal;
//    }
//}

// HEALTH STATUS BOOLEANS
//------------------------------------------------------------------------
bool Animals::isHealthy() {
    if (mHealth > 130 && mHealth <= 200)  //Healthy: 130-200
        return true;
        else return false;
}
bool Animals::isHungry() {
    if (mHealth > 70 && mHealth <= 130)  //Hungry: 70-130
        return true;
        else return false;
}
bool Animals::isStarving() {
    if (mHealth > 0 && mHealth <= 70)  //Healthy: 0-70
        return true;
        else return false;
}
bool Animals::isDead() {
    if (mHealth <= 0.0)
        return true;
        else return false;
}


// HOW TO CHANGE BODY COLOUR TO SHOW HEALTH STATUS
//------------------------------------------------------------------------
ofColor Animals::changeColour(ofColor healthyCol) {
   
    ofColor bodyColor;
    
    if (isHealthy()) bodyColor = healthyCol; //healthy color depends on the 'bodyColor' value defined in Frogs and BigFish (each animal has its own unique color)
    else if (isHungry()) bodyColor = hungryColor;  //turns orange
    else if (isStarving())  bodyColor = starvingColor; //turns red

    return bodyColor;
}

// DECREASE HEALTH as long as the Animal's alive but doesn't have any food to eat
//------------------------------------------------------------------------
void Animals::decreaseHealth() {
    mHealth -= 0.05;
    cout << mHealth << endl;
}

