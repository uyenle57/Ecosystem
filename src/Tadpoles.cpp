//
//  Tadpoles.cpp
//  cppUyen2
//
//  Created by Uyen Le on 25/02/2016.
//
//

#include "Tadpoles.hpp"

Tadpoles::Tadpoles(float posx, float posy, float posz) {
    
    mMaxSpeed = 3;
    mMaxForce = 0.2;
    mVelocity.set(ofRandom(1,4), ofRandom(1,4));
}

Tadpoles::~Tadpoles() {
    
}

void Tadpoles::borders() {
    
}

void Tadpoles::draw() {
    
    //Has a head and a wiggling tail that uses oscillation
    ofSetColor(255);
    ofDrawCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, 10);
}

//Swim in aligment with neighboring tadpoles
void Tadpoles:: swim(vector<&Tadpoles> neighbors) {
    
    float neighborDistance = 30;
    ofVec3f sum(0, 0);
    int count = 0;
    
    for (auto & other : neighbors) {
        float dist = mPosition.distance(other.mPosition);
        
        if ((dist > 0) && (dist < neighborDistance)) {
            sum = sum + other.mVelocity;
            count++;
        }
    }
    if (count > 0) {
        sum = sum / float(count);
        sum.normalize();
        sum = sum * mMaxSpeed;
        ofVec3f steer = sum - mVelocity;
        steer.limit(mMaxForce);
        applyForce(steer);
    }
    
}