//
//  Leeches.cpp
//  cppUyen2
//
//  Created by Uyen Le on 21/02/2016.
//
// Derived Organism 2

#include "Leeches.hpp"

Leeches::Leeches(float leechPosX, float leechPosY, float leechPosZ): Organism(leechPosX, leechPosY, leechPosZ) {
    mPosition.set(leechPosX+300, leechPosY, leechPosZ);
}

//Leeches::~Leeches() {
//    cout << "A leech has died" << endl;
//}

//--------------------------------------------------------------
void Leeches::draw() {
    
    ofScale(0.1, 0.15);  //scale down because the original leech is quite big
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    ofSetColor(0);
    
    //Leech is made up of 2 wiggle lines
    ofBeginShape();
    float speed = (abs(mPosition.x) + abs(mPosition.y)) *0.02;
    
    //right line
    for(int i=0; i < 180; i += 20) {
        x = sin(ofDegToRad(i)) * i/2;
        angle = speed *sin( ofDegToRad(i+a+ofGetFrameNum()*50) *50); //the wiggle movement
        ofVertex(x-angle, i*2.5);  //pass in the angle variable to the x position so that it wiggles
        ofVertex(x-angle, i*2.5);
    }
    
    //left line
    for (int j= 180; j > 0; j -= 20) {
        x = sin(ofDegToRad(j)) * j/2;
        angle = speed *sin( ofDegToRad(j+a+ofGetFrameNum()*50) *50);
        ofVertex(-x-angle, j*2.5);  //reverse the x positions to draw opposite to the first line
        ofVertex(-x-angle, j*2.5);
    }
    ofEndShape();
}

//--------------------------------------------------------------
void Leeches::swim() {
    mPosition.y += 1.5;
}

//--------------------------------------------------------------
void Leeches::movement() {
    
}

//--------------------------------------------------------------
void Leeches::returnToScreen() {
    
}

//--------------------------------------------------------------
void Leeches::update() {
    organism_Update();
    swim();
    movement();
    returnToScreen();
}

