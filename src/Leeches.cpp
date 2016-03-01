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
    mPrevPos.set(0, 0, 0);
}

//Leeches::~Leeches() {
//    cout << "A leech has been eaten" << endl;
//}

//--------------------------------------------------------------
void Leeches::draw() {
    
    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z); //*0.4 to decrease spacing between each Leech
    ofRotate(ofRadToDeg(rotateAngle)); //rotate the leech according to mouse position
    ofScale(0.1, 0.15); //scale down because original leech is really big
    
    //Leech is made up of 2 wiggle lines
    ofBeginShape();
    ofSetColor(30,30,30);
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
    
    ofDrawBitmapString("Leech", 5, 0, 0);
    ofPopMatrix();
}

//--------------------------------------------------------------
void Leeches::swim(float swimToX, float swimToY) {
    
    float catchUpSpeed = 0.6f;
    
    mPosition.x = catchUpSpeed * swimToX + (1-catchUpSpeed) * mPosition.x;
    mPosition.y = catchUpSpeed * swimToY + (1-catchUpSpeed) * mPosition.y;
    
    float distanceX = mPosition.x - mPrevPos.x;
    float distanceY = mPosition.y - mPrevPos.y;
    
    rotateAngle = atan2(distanceY, distanceX); //calculate angle between previous and current positions

//    mPrevPos.x = mPosition.x; //swim to the current mouse position
//    mPrevPos.y = mPosition.y;
}

//--------------------------------------------------------------
void Leeches::swim() {
    mPosition.y -= 0.5; //temporary movement
}

//--------------------------------------------------------------
void Leeches::movement() {
    //may delete this function as not needed
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
    swim();
//    swim(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    movement();
}

