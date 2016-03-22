//
//  babyFish.cpp
//  cppUyen2
//
//  Created by Uyen Le on 21/03/2016.
//
//

#include "babyFish.hpp"

babyFish::babyFish(float babyFishX, float babyFishY, float babyFishZ, DNA &dna) : BigFish(babyFishX, babyFishY, babyFishZ, dna) {
    
    mPosition.set(babyFishX, babyFishY, babyFishZ);
    
    mSize = ofMap(dna.genes[0], 0, 1, 5,5);
}

babyFish::~babyFish() {
    cout << "baby fish killed" << endl;
}

//------------------------------------------------------------------------------------
void babyFish::draw() {
    mRotateTheta = atan2(mVelocity.y, mVelocity.x);
    
    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    ofRotate(ofRadToDeg(mRotateTheta + 3*PI/2));
    ofScale(0.06, 0.06);
    
    ofSetColor(changeColour(bodyColor));
    
    ofBeginShape();
    int bodyLength = 5;
    for(int i=0; i < 180; i += 20) {
        float x = sin(ofDegToRad(i)) * i/2;
        ofVertex(x*mSize + wiggle(i), i*bodyLength);
        ofVertex(x*mSize + wiggle(i), i*bodyLength);
    }
    for (int j=180; j > 0; j -= 20) {
        float x = sin(ofDegToRad(j)) * j/2;
        ofVertex(-x*mSize + wiggle(j), j*bodyLength);
        ofVertex(-x*mSize + wiggle(j), j*bodyLength);
    }
    ofEndShape();
    
    //Tail
    ofSetColor(tailColor);
    ofBeginShape(); //left
    ofScale(9,7);
    ofCurveVertex(-0, 20); ofCurveVertex(0, 0); ofCurveVertex(-30, -5);
    ofCurveVertex(-0, 25); ofCurveVertex(0, 0);
    ofEndShape();
    ofBeginShape(); //right
    ofCurveVertex(0, 20); ofCurveVertex(0, 0); ofCurveVertex(30, -5);
    ofCurveVertex(0, 25); ofCurveVertex(0, 0);
    ofEndShape();
    
    //Eyes
    ofSetColor(255);
    ofDrawCircle(-10, 100, 5); ofDrawCircle( 10, 100, 5);
    ofSetColor(0);
    ofDrawCircle(-10, 100, 3); ofDrawCircle( 10, 100, 3);
    
    ofPopMatrix();
}

void babyFish::update() {
    BigFish::update();
}
