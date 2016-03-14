//
//  Animals.cpp
//  cppUyen2
//
//  Created by Uyen Le on 26/02/2016.
//
//  Base class Animals

#include "Animals.hpp"


DNA::DNA() {
    //something...
}

Animals::Animals(float x, float y, float z): mPosx(x), mPosy(y), mPosz(z){
    mPosition.set(0, 0, 0);
    mVelocity.set(0, 0, 0);
    mAcceleration.set(0, 0, 0);
    
    //Initialise a population of 100 DNA objects
//    dna.push_back(100);
}

void Animals::returnToScreen() {
    if(mPosition.x < -mBorder)  mPosition.x = ofGetWidth() + mBorder;
    if(mPosition.y < -mBorder)  mPosition.y = ofGetHeight() + mBorder;
    if(mPosition.x > ofGetWidth()+mBorder)  mPosition.x = -mBorder;
    if(mPosition.y > ofGetHeight()+mBorder)  mPosition.y = -mBorder;
}