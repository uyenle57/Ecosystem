//
//  Mosquitoes.cpp
//  cppUyen2
//
//  Created by Uyen Le on 26/02/2016.
//
// Derived Organism 3

#include "Mosquitoes.hpp"

Mosquitoes::Mosquitoes(float MosPosX, float MosPosY, float MosPosZ) : Organism(MosPosX, MosPosY, MosPosZ) {
    mPosition.set(MosPosX, MosPosY, MosPosZ);
}

//Mosquitoes::~Mosquitoes() {
//    
//}

//--------------------------------------------------------------
void Mosquitoes::draw() {
    
    //Create the mosquito shape
    ofPushMatrix();
    ofTranslate(mPosition.x * 0.8, mPosition.y, mPosition.z);
    
    ofBeginShape();
    ofSetColor(168,161,151);
    ofDrawCircle(0,0,0,4);       //Head
    ofDrawEllipse(0, 16, 7, 30); //Body
    
    // 2 flapping wings
    ofSetColor(33,33,33,50);
    ofDrawEllipse(-13, 8 + flappyWings(), 25, 7);
    ofDrawEllipse(13, 8 + flappyWings(), 25, 7);
    
    //Mouth
    ofSetColor(0);
    ofDrawLine(0, 0-3, 0, 0-20);
    ofEndShape();
    ofPopMatrix();
}

//--------------------------------------------------------------
void Mosquitoes::swim() {
    int amp = 10;
    mPosition.x += amp * sin(ofDegToRad(ofGetFrameNum() * ofRandom(20)));
    mPosition.y += amp * cos(ofDegToRad(ofGetFrameNum() * ofRandom(20)));
}

//--------------------------------------------------------------
void Mosquitoes::movement() {
    
}

//--------------------------------------------------------------
float Mosquitoes::flappyWings() {
    int amp = 5;
    int speed = 50;
    float letsGetFlappy = amp * sin(ofDegToRad(ofGetFrameNum()*speed));
    
    return letsGetFlappy;
}

//--------------------------------------------------------------
void Mosquitoes::update() {
    organism_Update();
    organism_returnToScreen();
    swim();
    movement();
}



