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
    SmallFish(float smallFishX, float smallFishY, float smallFishZ, DNA &dna);
    
    ~SmallFish();
    
    void draw(), update(), swim(), eat();
    void update(SmallFish &neighbor);
    void swim(SmallFish &neighbor);

    //Flocking (cohesion, alignment and seperation)
    ofVec3f Attraction(SmallFish &neighbor);
    ofVec3f Alignment(SmallFish &neighbor);
    ofVec3f Repulsion(SmallFish &neighbor);
    
    void updateForce();
    void applyDamping();
    
    float mDamping, mDistance, mStrength;
    int mCount;
    ofVec3f sum;
    
    bool bIsClose;
    
private:
    ofColor(healthyColor);
    float wiggle(int m);
};


#endif /* SmallFish_hpp */
