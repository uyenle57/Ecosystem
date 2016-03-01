//
//  Leeches.cpp
//  cppUyen2
//
//  Created by Uyen Le on 21/02/2016.
//
// Derived Organism 2

#include "Leeches.hpp"

Leeches::Leeches(float leechPosX, float leechPosY, float leechPosZ): Organism(leechPosX, leechPosY, leechPosZ) {
    mPosition.set(leechPosX, leechPosY, leechPosZ);
}

//Leeches::~Leeches() {
//    cout << "A leech has died" << endl;
//}

//--------------------------------------------------------------
void Leeches::draw() {
    
    ofPushMatrix();
    ofTranslate(mPosition.x*0.4, mPosition.y, mPosition.z); //*0.4 to decrease spacing between each Leech
    ofScale(0.1, 0.15);  //scale down because the original leech is quite big
    ofSetColor(0);
    
    //Leech is made up of 2 wiggle lines
    ofBeginShape();
    
    float x;
    int bodyLength = 2;
    
    //right line
    for(int i=0; i < 180; i += 20) {
        x = sin(ofDegToRad(i)) * i/2;
        ofVertex(x+wiggle(i), i*bodyLength);  //pass in the angle variable to the x position so that it wiggles
        ofVertex(x+wiggle(i), i*bodyLength);
    }
    
    //left line
    for (int j=180; j > 0; j -= 20) {
        x = sin(ofDegToRad(j)) * j/2;
        ofVertex(-x+wiggle(j), j*bodyLength);  //reverse the x positions to draw opposite to the first line
        ofVertex(-x+wiggle(j), j*bodyLength);
    }
    ofEndShape();
    ofPopMatrix();
}

//--------------------------------------------------------------
void Leeches::swim() {
    float angle = mVelocity.x + ofDegToRad(ofRandom(-90,90));
    ofRotate(angle);
    
    mPosition.x += ofRandom(-5,5);
}

//--------------------------------------------------------------
void Leeches::movement() {
    
}

//--------------------------------------------------------------
float Leeches::wiggle(int m) {
    int amount = 20;
    float amp = (abs(mPosition.x) + abs(mPosition.y)) * 0.04;
    
    float letsWiggle = amp * sin(ofDegToRad(float(m)+(ofGetFrameNum()/2)) * amount);
    
    return letsWiggle;
}

//--------------------------------------------------------------
void Leeches::update() {
    organism_Update();
    organism_returnToScreen();
    //swim();
    movement();
}

