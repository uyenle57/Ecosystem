//
//  SmallFish.hpp
//  cppUyen2
//
//  Created by Uyen Le on 13/03/2016.
//
//  Groups of small fish with flocking behaviour

#ifndef SmallFish_hpp
#define SmallFish_hpp

#include <stdio.h>
#include "Animals.hpp"


class SmallFish : public Animals {

public:
    SmallFish(float fishPosX, float fishPosY, float fishPosZ);
    
    virtual ~SmallFish();
    
    void draw(), update(), swim(), mate(), eat(), changeColor();
    
    ofColor(bodyColor);
    
    //Flocking
    //based on 3 rules: cohesion, alignment and seperation
    void addAttraction(SmallFish &neighbor);
    void addAlignment(SmallFish &neighbor, float radius, float scale);
    void addRepulsion(SmallFish &neighbor, float radius, float scale);
    
    void moveAwayFromMouse(float mousex, float mousey, float radius, float scale);

    void applyForce(ofVec3f force);
    void updateForce();
    void resetForce();
    void applyDamping();
    void seekTarget(ofVec3f target);
    
    float mDamping, mMaxForce, mMaxSpeed, mDistance;
    int mCount;
    
    bool bIsClose;
};


#endif /* SmallFish_hpp */
