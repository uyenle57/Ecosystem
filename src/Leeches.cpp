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
    
    bodyLength = 2;
    bodyColor.set(30,30,30);
}

//Leeches::~Leeches() {
//    cout << "A leech has been eaten" << endl;
//}

//--------------------------------------------------------------
void Leeches::draw() {
    
    mRotateTheta = atan2(mVelocity.y, mVelocity.x); //Make the Worms rotate according to velocity

    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z); //*0.4 to decrease spacing between each Leech
    ofRotate(ofRadToDeg(mRotateTheta)+ofRadToDeg(3*PI/2));
    ofScale(0.1, 0.15); //scale down because original leech is really big
    
    //Leech is made up of 2 wiggle lines
    ofBeginShape();
    ofSetColor(bodyColor);
    
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
void Leeches:: swim() {   //Wander around
    float radius = 20;
    float distance = 80;
    
    wanderAngle += ofRandom(-0.1, 0.1);
    
    ofVec3f wanderAround = mVelocity; //an invisible position that leads the Worms
    wanderAround.normalize();
    wanderAround *= distance;
    wanderAround += mPosition;  //make 'wanderAround' relative to Worm's position
    
    ofVec3f wanderOffset(radius*(cos(wanderAngle)*0.5), radius*(sin(wanderAngle)*0.5) );
    ofVec3f target = wanderAround + wanderOffset;
    
    seekTarget(target);
}

//--------------------------------------------------------------
float Leeches::wiggle(int m) {
    float amp = (abs(mPosition.x) + abs(mPosition.y)) * 0.04;
    float letsWiggle = amp * sin(ofDegToRad(float(m)+(ofGetFrameNum()/2)) * 20);
    
    return letsWiggle;
}

//--------------------------------------------------------------
void Leeches::update() {
    organism_Update();
    organism_returnToScreen();
    swim();
}

