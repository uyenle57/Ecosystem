//
//  Worms.cpp
//  cppUyen2
//
//  Created by Uyen Le on 21/02/2016.
//
// Derived Organism 1

#include "Worms.hpp"


Worms::Worms(float wormPosX, float wormPosY, float wormPosZ): Organism(wormPosX, wormPosY, wormPosZ) {
    mPosition.set(wormPosX+300, wormPosY, wormPosZ);
}

//Worms::~Worms() {
//    cout << "A worm has died" << endl;
//}

//--------------------------------------------------------------
void Worms::eat() {

}

//--------------------------------------------------------------
void Worms:: swim() {
    float radius = 20;
    float distance = 80;
    
    mTheta += ofRandom(-0.5, 0.5);
    
    //Create an invisible "leader" for the Worm to follow
    ofVec3f leaderPos = mVelocity;
    leaderPos.normalize();
    leaderPos *= distance;
    leaderPos += mPosition;  //make it relative to Worm's position
    
    float h = mVelocity.angle(mPosition);
    ofVec3f leaderOffset ( radius*cos(mTheta+h), radius*sin(mTheta+h) );
    ofVec3f target = leaderPos + leaderOffset;
    
    seekTarget(target);
}

//--------------------------------------------------------------
void Worms:: movement() {

}

// Wrap borders to make objects return to screen if they go offscreen
//--------------------------------------------------------------
void Worms::returnToScreen(){
    
    if (mPosition.x < -r)   mPosition.x = ofGetWindowWidth()+r;
    if (mPosition.y < -r)   mPosition.y = ofGetWindowHeight()+r;
    if (mPosition.x > ofGetWindowWidth()+r)    mPosition.x = -r;
    if (mPosition.y > ofGetWindowHeight()+r)   mPosition.y = -r;
}

//--------------------------------------------------------------
void Worms::update() {
    organism_Update();  //from Base class Organism
    swim();
    movement();
    returnToScreen();
}

//--------------------------------------------------------------
void Worms:: draw() {
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    float theta = mVelocity.x + ofDegToRad(45);
    //ofRotate(theta);
    
    ofSetColor(255,0,0);
    ofDrawTriangle(0,-r*2,-r,r*2,r,r*2);
}

