//
//  SmallFish.cpp
//  cppUyen2
//
//  Created by Uyen Le on 13/03/2016.
//
//

#include "SmallFish.hpp"


SmallFish::SmallFish(float smallFishX, float smallFishY, float smallFishZ) : Animals(smallFishX, smallFishY, smallFishZ) {
    mPosition.set(smallFishX, smallFishY, smallFishZ);
    sum.set(0,0,0);
    
    mDamping = 0.01f;
    mDistance = 50;
    mCount = 0;
    
    mMaxForce = ofMap(dna.genes[0], 0, 1, 0.05, 0.05);
    mMaxSpeed = ofMap(dna.genes[0], 0, 1, 3, 3);
    mSize = ofMap(dna.genes[0], 0, 1, 5,5);
        
    healthyColor.set(137, 212, 211);
    hungryColor.set(255,190,10); //orange
    starvingColor.set(255,0,0);  //red
}

SmallFish::~SmallFish() {
    
}

//------------------------------------------------------------------------------------
void SmallFish::draw() {
    mRotateTheta = atan2(mVelocity.y, mVelocity.x);
    
    ofPushMatrix();
    ofTranslate(mPosition.x, mPosition.y, mPosition.z);
    ofRotate(ofRadToDeg(mRotateTheta + 3*PI/2));
    ofScale(0.07, 0.07);
    ofSetColor(healthyColor);
    
    //Body is created with 2 lines (same as Leeches)
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
    ofSetColor(255,97,105);
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

//------------------------------------------------------------------------------------
void SmallFish::update(SmallFish &neighbor) {
    Animals::swim();
    Animals::update();
    Animals::returnToScreen();
    
    swim(neighbor);
}

// FLOCKING BEHAVIOUR
//------------------------------------------------------------------------------------
ofVec3f SmallFish::Attraction(SmallFish &neighbor) {
//    float dist = mPosition.distance(neighbor.mPosition); //Calculate the distance between the current and neighour fishes
//    
//    if (dist > 0 && dist < mDistance) {  //Check that the current fish is close to neighbor fishes
//        sum += neighbor.mPosition;
//        mCount++;
//    }
//    if (mCount > 0) {
//        sum /= mCount;
//        return seekFish(sum); //steer towards neighbor fish
//    }
//    else return ofVec3f(0,0,0);
}

//------------------------------------------------------------------------------------
ofVec3f SmallFish::Alignment(SmallFish &neighbor) {
    
    ofVec3f diff = mPosition - neighbor.mPosition;
    float dist = diff.length(); //compute magnitude of that difference
    diff.normalize();
    
    if (dist > 0 && dist < mDistance) {  //Check that the current fish is close to neighbor fishes
        sum += neighbor.mVelocity;
        mCount++;
    }
    if (mCount > 0) {
        sum /= float(mCount);
        sum.normalize();
        sum *= mMaxSpeed;
        ofVec3f steer = sum - mVelocity;
        steer.limit(mMaxForce);
        return steer;
    }
    else return ofVec3f(0,0,0);
}

//------------------------------------------------------------------------------------
ofVec3f SmallFish::Repulsion(SmallFish &neighbor) {
    float sepAmount = 25.0f;
    ofVec3f steer(0,0,0);
    
    //Check if every fish is too close to neighbor fish
    float dist = mPosition.distance(neighbor.mPosition);
    
    if (dist > 0 && dist < sepAmount) {
        ofVec3f diff = mPosition - neighbor.mPosition;
        diff.normalize();
        diff /= dist; //Weight by distance
        steer += diff;
        mCount++; //Keep track of how many
    }
    //Average
    if (mCount > 0) {
        steer /= (float(mCount));
    }
    //As long as the vector is greater than 0
    if (steer.length() > 0) {
        //Implement Reynolds: Steering = Desired - Velocity
        steer.normalize();
        steer *= mMaxSpeed;
        steer -= mVelocity;
        steer.limit(mMaxForce);
    }
    return steer;
}

//------------------------------------------------------------------------------------
void SmallFish::swim(SmallFish &neighbor) { //Flocking
    ofVec3f attract = Attraction(neighbor);
    ofVec3f align = Alignment(neighbor);
    ofVec3f repulse = Repulsion(neighbor);
    
    //Arbitrarily weight these forces
    attract * 1.5;
    align * 1.5;
    repulse * 1.0;
    //Add these forces to acceleration
    applyForce(attract);
    //applyForce(align);
    //applyForce(repulse);
}

//------------------------------------------------------------------------------------
//void SmallFish::moveAwayFromMouse(float mousex, float mousey, float radius, float scale) {
//    ofVec2f posOfForce;
//    posOfForce.set(mousex, mousey);
//    
//    ofVec2f diff = mPosition - posOfForce;
//    float length = diff.length();
//    
//    if (radius > 0) {
//        if (length > radius){
//            bIsClose = false;
//        }
//    }
//    if (bIsClose == true) {
//        float pct = 1 - (length / radius);  // stronger on the inside
//        diff.normalize();
//        mAcceleration.x = mAcceleration.x - diff.x * scale * pct;
//        mAcceleration.y = mAcceleration.y - diff.y * scale * pct;
//    }
//}

//------------------------------------------------------------------------------------
void SmallFish::applyDamping() {
    
}

//------------------------------------------------------------------------------------
void SmallFish::update() {
    //small fish have their own update function (see above)
    //empty
}
//------------------------------------------------------------------------------------
void SmallFish::swim() {
    //small fish have their own swim function (see above)
    //empty
}

//------------------------------------------------------------------------------------
float SmallFish::wiggle(int m) {
    float letsWiggle = 15 * sin(ofDegToRad(float(m)+(ofGetFrameNum()/2))*20);
    return letsWiggle;
}

