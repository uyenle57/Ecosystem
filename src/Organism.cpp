//
//  Organism.cpp
//  cppUyen2
//
//  Created by Uyen Le on 16/02/2016.
//
//

#include "Organism.hpp"

//Organism::Organism(int posx, int posy, int posz):mPosx(posx), mPosy(posy), mPosz(posz) {
Organism::Organism() {
    color.set(255);
    
}

void Organism::Draw() {
    
    ofSetColor(color);
    //ofDrawEllipse(mPosx, mPosy, mPosz, 10);
    ofDrawEllipse(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 10, 10);
}

void Organism::Move() {
    
    mPosx += 0.05;
}