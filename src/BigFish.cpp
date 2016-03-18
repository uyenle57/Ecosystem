//
//  BigFish.cpp
//  cppUyen2
//
//  Created by Uyen Le on 13/03/2016.
//
//

#include "BigFish.hpp"

BigFish::BigFish(float bigFishX, float bigFishY, float bigFishZ) : Animals(bigFishX, bigFishY, bigFishZ) {
    mPosition.set(bigFishX, bigFishY, bigFishZ);
    
    healthyColor.set(20,40,160); //dark blue
    hungryColor.set(255,190,10);  //orange
    starvingColor.set(255,0,0);  //red
    
    mMaxForce = ofMap(dna.genes[0], 0, 1, 0.01, 0.03);
    mMaxSpeed = ofMap(dna.genes[0], 0, 1, 1, 10);
    mSize = ofMap(dna.genes[0], 0, 1, 5,5);
}

BigFish::~BigFish() {
    
}

//------------------------------------------------------------------------------------
void BigFish::draw() {
    mRotateTheta = atan2(mVelocity.y, mVelocity.x);
    
    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    ofRotate(ofRadToDeg(mRotateTheta));
    ofScale(0.1, 0.15);
    ofSetColor(healthyColor);

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
    ofSetColor(255,180,6);
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
    Animals::swim();
    Animals::update();
    Animals::returnToScreen();
    
    mLifespan -= 0.2;
}

//------------------------------------------------------------------------------------
void BigFish::swim() {
//    // Simple movement with Perlin Noise
//    float dirx = ofMap(ofNoise(xoff), 0,1, -mMaxSpeed,mMaxSpeed);
//    float diry = ofMap(ofNoise(yoff), 0,1, -mMaxSpeed,mMaxSpeed);
//    newVel.set(dirx, diry);
//    
//    xoff += mMaxForce;
//    yoff += mMaxForce;
//    
//    mPosition += newVel;
}

//------------------------------------------------------------------------------------
float BigFish::wiggle(int m) {
    float letsWiggle = 15 * sin(ofDegToRad(float(m)+(ofGetFrameNum()/2))*20);
    return letsWiggle;
}
