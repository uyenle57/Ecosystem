//
//  Leeches.cpp
//  cppUyen2
//
//  Created by Uyen Le on 21/02/2016.
//
// Derived Organism 2

#include "Leeches.hpp"

Leeches::Leeches() {

}

Leeches::~Leeches() {
    
}

//--------------------------------------------------------------
void Leeches::draw() {
    
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    
    ofSetColor(0,0,255);
    ofDrawRectangle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 20,20);
}

//--------------------------------------------------------------
void Leeches::swim() {
    
    mPosition.y -= 0.5;
    
}

//--------------------------------------------------------------
void Leeches::movement() {
    
}

//--------------------------------------------------------------
void Leeches::mate() {
    
}