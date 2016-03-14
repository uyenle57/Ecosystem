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
}

Frogs::~Frogs() {
    
}

//------------------------------------------------------------------------------------
void Frogs::draw() {
    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    
    //Create the frog shape
    //Body
    ofSetColor(4, 153, 0, 60);
    //ofSetColor(0, greenBodyCol, 0, health); //for changing body color according to health status
    ofDrawCircle(0,0, 50);

    //Legs (thighs + feet)
    ofBeginShape();         //left thigh
    ofCurveVertex(-20, 50+flappyLegs());
    ofCurveVertex(-45, 20+flappyLegs());
    ofCurveVertex(-70, 15+flappyLegs());
    ofCurveVertex(-30, 45+flappyLegs());
    ofCurveVertex(0, 0);
    ofEndShape();
    
    ofBeginShape();         //right thigh
    ofCurveVertex(20, 50+flappyLegs());
    ofCurveVertex(45, 20+flappyLegs());
    ofCurveVertex(70, 15+flappyLegs());
    ofCurveVertex(30, 45+flappyLegs());
    ofCurveVertex(0, 0);
    ofEndShape();
    
    ofDrawTriangle(-30, 40+flappyLegs(), -50, 60+flappyLegs(), -40, 70+flappyLegs()); //left foot
    ofDrawTriangle( 30, 40+flappyLegs(),  50, 60+flappyLegs(),  40, 70+flappyLegs()); //right foot
    
    //Eyes
    ofSetColor(0);
    ofDrawCircle(-20,-40, 5); //left eye
    ofDrawCircle( 20,-40, 5); //right eye
    ofPopMatrix();
}

//------------------------------------------------------------------------------------
void Frogs:: update() {
    
}

//------------------------------------------------------------------------------------
void Frogs::swim() {
    
}

//------------------------------------------------------------------------------------
float Frogs::flappyLegs() {
    int amp = 5;
    int speed = 5;
    float letsGetFlappy = amp * sin(ofDegToRad(ofGetFrameNum()*speed));
    
    return letsGetFlappy;
}

//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------
