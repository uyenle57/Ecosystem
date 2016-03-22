//
//  babyFrog.cpp
//  cppUyen2
//
//  Created by Uyen Le on 21/03/2016.
//
//

#include "babyFrog.hpp"

babyFrog::babyFrog(float babyFrogX, float babyFrogY, float babyFrogZ, DNA &dna) : Frogs(babyFrogX, babyFrogY, babyFrogZ, dna) {
    
    mPosition.set(babyFrogX, babyFrogY, babyFrogZ);
    
    mSize = ofMap(dna.genes[0], 0, 1, 30, 30);
    
    species = "babyFrog"; //set different species name to prevent baby animals from reproducing
}

babyFrog::~babyFrog() {
    cout << "Baby died" << endl;
}

void babyFrog::draw() {
    mRotateTheta = atan2(mVelocity.y, mVelocity.x);
    
    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    ofRotate(ofRadToDeg(mRotateTheta));
    
    //The frog shape
    //Body
    ofSetColor(changeColour(bodyColor));
    ofDrawCircle(0, 0, mSize);
    ofScale(0.6, 0.6);
    
    //Legs (thighs + feet)
    ofBeginShape();  //left thigh
    ofCurveVertex(-20, 50); ofCurveVertex(-45, 20); ofCurveVertex(-70, 15);
    ofCurveVertex(-30, 45); ofCurveVertex(0, 0);
    ofEndShape();
    
    ofBeginShape();  //right thigh
    ofCurveVertex(20, 50); ofCurveVertex(45, 20); ofCurveVertex(70, 15);
    ofCurveVertex(30, 45); ofCurveVertex(0, 0);
    ofEndShape();
    
    ofDrawTriangle(-30, 40, -50, 60, -40, 70); //left foot
    ofDrawTriangle( 30, 40,  50, 60,  40, 70); //right foot
    
    //Eyes
    ofSetColor(0);
    ofDrawCircle(-20,-40, 5); //left eye
    ofDrawCircle( 20,-40, 5); //right eye
    
    ofPopMatrix();
}

void babyFrog::update() {
    Frogs::update();
}

