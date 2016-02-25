//
//  Worms.cpp
//  cppUyen2
//
//  Created by Uyen Le on 21/02/2016.
//
//

#include "Worms.hpp"


Worms::Worms() {
    
    //mPosition.set(ofGetWindowWidth(), ofGetWindowHeight()/2, 15);
}

//--------------------------------------------------------------
Worms::~Worms() {
    
}

void Worms::run() {
    swim();
    update();
}

//--------------------------------------------------------------
void Worms:: swim() {
    
    mTheta += ofRandom(-0.05, 0.05); //randomise wander theta
    
    //Create a black spot as the "leader" for the Worm to follow
    ofVec3f leaderPos = mVelocity;
    leaderPos.normalize();
    leaderPos = leaderPos * 80; //multiply by 80 (distance)
    leaderPos = leaderPos + mPosition;  //make it relative to Worm's position
    
    float h = mVelocity.angle(mPosition);
    ofVec3f leaderOffset (25*cos(mTheta+h), 25*sin(mTheta+h));
    
    ofVec3f target = leaderPos + leaderOffset;
    
    seek(target);
}

//--------------------------------------------------------------
void Worms:: draw() {
    
    float theta = mVelocity.x + ofDegToRad(90);
    
    //ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    ofRotate(theta);
    
    ofSetColor(255,0,0);
    ofDrawCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 15);
}

//--------------------------------------------------------------
void Worms:: movement() {

}

//--------------------------------------------------------------
void Worms:: mate() {

}

//--------------------------------------------------------------
void Worms::borders() {

}

