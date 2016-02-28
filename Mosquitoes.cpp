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
    ofBeginShape();
    ofSetColor(168,161,151);
    ofDrawCircle(mPosition.x, mPosition.y, mPosition.z, 4); //Head
    ofDrawEllipse(mPosition.x, mPosition.y+16, 7, 30); //Body
    // 2 wings
    ofSetColor(33,33,33,50);
    ofDrawEllipse(mPosition.x-13, mPosition.y+8, 25, 7);
    ofDrawEllipse(mPosition.x+13, mPosition.y+8, 25, 7);
    //Mouth
    ofSetColor(0);
    ofDrawLine(mPosition.x, mPosition.y-3, mPosition.x, mPosition.y-20);
    ofEndShape();
}

//--------------------------------------------------------------
void Mosquitoes::swim() {
    //mPosition.x += ofRandom(ofGetWindowWidth());
}

//--------------------------------------------------------------
void Mosquitoes::movement() {
    
}

//--------------------------------------------------------------
void Mosquitoes::returnToScreen() {
    
}

//--------------------------------------------------------------
void Mosquitoes::update() {
    organism_Update();
    swim();
    movement();
    returnToScreen();
}



