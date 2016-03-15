//
//  BigFish.cpp
//  cppUyen2
//
//  Created by Uyen Le on 13/03/2016.
//
//

#include "BigFish.hpp"

BigFish::BigFish(float bigFishX, float bigFishY, float bigFishZ) : Animals(bigFishX, bigFishY, bigFishZ) {
    
    //Animals::healthyColor.set(4,153,0); //colorful fish
    //Animals::hungryColor.set(255,190,10);  //orange
    //Animals::starvingColor.set(255,0,0);  //red
    
    mMaxForce = ofMap(dna.genes[0], 0, 1, 0, 10.0);
    mMaxSpeed = ofMap(dna.genes[0], 0, 1, 0, 10.0);
    mSize = ofMap(dna.genes[0], 0, 1, 50, 50);
}

BigFish::~BigFish() {
    
}

//------------------------------------------------------------------------------------
void BigFish::draw() {
    
}

//------------------------------------------------------------------------------------
void BigFish::update() {
    
}