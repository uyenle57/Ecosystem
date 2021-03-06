//
//  BigFish.cpp
//  cppUyen2
//
//  Created by Uyen Le on 13/03/2016.
//
//

#include "BigFish.hpp"

BigFish::BigFish(float bigFishX, float bigFishY, float bigFishZ, DNA &dna) : Animals(bigFishX, bigFishY, bigFishZ, dna) {
    
    mPosition.set(bigFishX, bigFishY, bigFishZ);
    
    bodyColor.set(20,40,160); //dark blue
    tailColor.set(135,7,83);
    
    mMaxForce = ofMap(dna.genes[0], 0, 1, 0.005, 0.005);
    mMaxSpeed = ofMap(dna.genes[0], 0, 1, 10, 15);
    mSize = ofMap(dna.genes[0], 0, 1, 5,5);
    
    xoff = ofRandom(1000);
    yoff = ofRandom(1000);
    
     species = "Fish";
}

BigFish::~BigFish() {
    cout << "Big fish killed" << endl;
}

//------------------------------------------------------------------------------------
void BigFish::draw() {
    mRotateTheta = atan2(mVelocity.y, mVelocity.x);
    
    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    ofRotate(ofRadToDeg(mRotateTheta + 3*PI/2));
    ofScale(0.1, 0.15);
    
    ofSetColor(changeColour(bodyColor));

    //Body is created with 2 lines (same as Leeches)
    ofBeginShape();
    int bodyLength = 5;
    for(int i=0; i < 180; i += 20) {
        float x = sin(ofDegToRad(i)) * i/2;
        ofVertex(x*mSize + wiggle(i), i*bodyLength);
        ofVertex(x*mSize + wiggle(i), i*bodyLength);
    }
    for (int j=180; j > 0; j -= 20) {
        float x = sin(ofDegToRad(j)) * j/2;
        ofVertex(-x*mSize + wiggle(j), j*bodyLength);
        ofVertex(-x*mSize + wiggle(j), j*bodyLength);
    }
    ofEndShape();
    
    //Tail
    ofSetColor(tailColor);
    ofBeginShape(); //left
    ofScale(9,7);
    ofCurveVertex(-0, 20); ofCurveVertex(0, 0); ofCurveVertex(-30, -5);
    ofCurveVertex(-0, 25); ofCurveVertex(0, 0);
    ofEndShape();
    ofBeginShape(); //right
    ofCurveVertex(0, 20); ofCurveVertex(0, 0); ofCurveVertex(30, -5);
    ofCurveVertex(0, 25); ofCurveVertex(0, 0);
    ofEndShape();
    
    //Eyes
    ofSetColor(255);
    ofDrawCircle(-10, 100, 5); ofDrawCircle( 10, 100, 5);
    ofSetColor(0);
    ofDrawCircle(-10, 100, 3); ofDrawCircle( 10, 100, 3);
    
    ofPopMatrix();
}

//------------------------------------------------------------------------------------
void BigFish::update() {
    BigFish::swim();
    Animals::decreaseHealth();
    Animals::returnToScreen();
}

//------------------------------------------------------------------------------------
void BigFish::swim() {
    float vx = ofMap(ofNoise(xoff), 0,1, -mMaxSpeed,mMaxSpeed);
    float vy = ofMap(ofNoise(yoff), 0,1, -mMaxSpeed,mMaxSpeed);
    mVelocity.set(vx,vy);
    
    xoff += mMaxForce;
    yoff += mMaxForce;
    
    mPosition += mVelocity;
}

//------------------------------------------------------------------------------------
float BigFish::wiggle(int m) {
    float letsWiggle = 20 * sin(ofDegToRad(float(m)+(ofGetFrameNum()/1.5))*20);
    return letsWiggle;
}

//------------------------------------------------------------------------------------
ofVec3f BigFish::getPos() {
    return BigFish::mPosition;
}
