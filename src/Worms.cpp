//
//  Worms.cpp
//  cppUyen2
//
//  Created by Uyen Le on 21/02/2016.
//
// Derived Organism 1

#include "Worms.hpp"


Worms::Worms(float wormPosX, float wormPosY, float wormPosZ): Organism(wormPosX, wormPosY, wormPosZ) {
    
    mPosition.set(wormPosX, wormPosY, wormPosZ);

//    rotateAmount.set(0,0,1);
//    rotateAngle = ofDegToRad(90);
}

//Worms::~Worms() {
//    cout << "A worm has been eaten" << endl;
//}

//--------------------------------------------------------------
void Worms:: draw() {

    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    ofSetColor(255,145,6); //orange worms
    ofSetLineWidth(3);

    // TODO: make worm rotate in the direction of velocity
    float theta = mPosition.angleRad(mVelocity);
    //ofRotate(theta);
    //mPosition.rotate(rotateAngle, rotateAmount);
    
    ofDrawLine(0, 0, 0, 0, 60, 0);  //temporary shape
    ofDrawBitmapString("Worm", 5, 0, 0);
    ofPopMatrix();
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
    
    float h = mVelocity.angle(mPosition); //return the angle between the Worm's velocity and position
    
    ofVec3f leaderOffset(radius*cos(mTheta+h), radius*sin(mTheta+h));
    ofVec3f target = leaderPos + leaderOffset;
    
    seekTarget(target);
}

//--------------------------------------------------------------
void Worms:: movement() {

}

//--------------------------------------------------------------
void Worms::update() {
    organism_Update();  //from Base class Organism
    organism_returnToScreen();
    swim();
    movement();
}

