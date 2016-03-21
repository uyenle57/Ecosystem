//
//  Frogs.cpp
//  cppUyen2
//
//  Created by Uyen Le on 13/03/2016.
//
//

#include "Frogs.hpp"

Frogs::Frogs(float frogPosX, float frogPosY, float frogPosZ, DNA &dna) : Animals(frogPosX, frogPosY, frogPosZ, dna) {
    
    mPosition.set(frogPosX, frogPosY, frogPosZ);
    
    bodyColor.set(4,153,0); //green
    
    //Weight of force, movement speed and body size are determined by DNA
    mMaxForce = ofMap(dna.genes[0], 0, 1, 0.01, 0.03);
    mMaxSpeed = ofMap(dna.genes[0], 0, 1, 5, 10);
    mSize = ofMap(dna.genes[0], 0, 1, 50, 50);
    
    xoff = ofRandom(1000);
    yoff = ofRandom(1000);
}

Frogs::~Frogs() {
    cout << "Frog killed" << endl;
}

//------------------------------------------------------------------------------------
void Frogs::draw() {
    mRotateTheta = atan2(mVelocity.y, mVelocity.x);
    
    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    ofRotate(ofRadToDeg(mRotateTheta));
    
    //The frog shape
    //Body
    ofSetColor(changeColour(bodyColor));
    ofDrawCircle(0, 0, mSize);

    //Legs (thighs + feet)
    ofBeginShape();  //left thigh
    ofCurveVertex(-20, 50); ofCurveVertex(-45, 20); ofCurveVertex(-70, 15);
    ofCurveVertex(-30, 45); ofCurveVertex(0, 0);
    ofEndShape();
    
    ofBeginShape();  //right thigh
    ofCurveVertex(20, 50); ofCurveVertex(45, 20); ofCurveVertex(70, 15);
    ofCurveVertex(30, 45); ofCurveVertex(0, 0);
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
    Frogs::eat();
    Animals::swim();
    Animals::update();
    Animals::decreaseHealth();
    Animals::returnToScreen();
}

//------------------------------------------------------------------------------------
void Frogs::swim() {
    // Simple movement with Perlin Noise
    float dirx = ofMap(ofNoise(xoff), 0,1, -mMaxSpeed,mMaxSpeed);
    float diry = ofMap(ofNoise(yoff), 0,1, -mMaxSpeed,mMaxSpeed);
    newVel.set(dirx, diry);
    
    xoff += mMaxForce;
    yoff += mMaxForce;
    
    mPosition += newVel;
}

//------------------------------------------------------------------------------------
void Frogs::eat() {

}

