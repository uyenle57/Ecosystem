//
//  Frogs.cpp
//  cppUyen2
//
//  Created by Uyen Le on 13/03/2016.
//
//

#include "Frogs.hpp"

Frogs::Frogs(float frogPosX, float frogPosY, float frogPosZ) : Animals(frogPosX, frogPosY, frogPosZ) {
    mPosition.set(frogPosX, frogPosY, frogPosZ);
    
    healthyColor.set(4,153,0); //green
    hungryColor.set(255,190,10);  //orange
    starvingColor.set(255,0,0);  //red
    
    //Weight of force, movement speed and body size are determined by DNA
    mMaxForce = ofMap(dna.genes[0], 0, 1, 0, 0.3);
    mMaxSpeed = ofMap(dna.genes[0], 0, 1, 5, 0);
    mSize = ofMap(dna.genes[0], 0, 1, 50, 50);
    
    xoff = yoff = ofRandom(500);
}

Frogs::~Frogs() {
    
}

//------------------------------------------------------------------------------------
void Frogs::draw() {
    
    Animals::mRotateTheta = atan2(newVel.y, newVel.x);

    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    //ofRotate(ofRadToDeg(mRotateTheta));
    
    //Create the frog shape
    //Body
    ofSetColor(healthyColor); //ofSetColor(0, greenBodyCol, 0, mLifeSpan);
    ofDrawCircle(0, 0, mSize);

    //Legs (thighs + feet)
    ofBeginShape();   //left thigh
    ofCurveVertex(-20 + flappyLegs(), 50);
    ofCurveVertex(-45 + flappyLegs(), 20);
    ofCurveVertex(-70 + flappyLegs(), 15);
    ofCurveVertex(-30 + flappyLegs(), 45);
    ofCurveVertex(0, 0);
    ofEndShape();
    
    ofBeginShape();   //right thigh
    ofCurveVertex(20, 50);
    ofCurveVertex(45, 20);
    ofCurveVertex(70, 15);
    ofCurveVertex(30, 45);
    ofCurveVertex(0, 0);
    ofEndShape();
    
    ofDrawTriangle(-30, 40, -50, 60, -40, 70); //left foot
    ofDrawTriangle( 30, 40,  50, 60,  40, 70); //right foot
    
    //Eyes
    ofSetColor(0);
    ofDrawCircle(-20,-40, 5); //left eye
    ofDrawCircle( 20,-40, 5); //right eye
    
    ofPopMatrix();
}

//------------------------------------------------------------------------------------
void Frogs::update() {
    Frogs::swim();
    Animals::returnToScreen();
    
    mLifespan -= 0.2;  //Decrease health as long as the Frogs are still alive
}

//------------------------------------------------------------------------------------
void Frogs::swim() {
    // Simple movement created with Perlin Noise
    float dirx = ofMap(ofSignedNoise(xoff), 0,1, -mMaxSpeed,mMaxSpeed);
    float diry = ofMap(ofSignedNoise(yoff), 0,1, -mMaxSpeed,mMaxSpeed);
    
    //ofVec3f newVel(dirx, diry);
    newVel.set(dirx, diry);
    
    xoff += ofRandom(mMaxForce);
    yoff += ofRandom(mMaxForce);
    
    mPosition += newVel;
}

//------------------------------------------------------------------------------------
float Frogs::flappyLegs() {
    int amp = 5;
    float letsGetFlappy = amp * sin(ofGetElapsedTimef()* mMaxSpeed);
    
    return letsGetFlappy;
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
