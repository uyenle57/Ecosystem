//
//  BigFish.hpp
//  cppUyen2
//
//  Created by Uyen Le on 13/03/2016.
//
//

#ifndef BigFish_hpp
#define BigFish_hpp

#include <stdio.h>
#include "Animals.hpp"

class BigFish : public Animals {
    
public:
    BigFish(float bigFishX, float bigFishY, float bigFishZ);
    virtual ~BigFish();
    
    void draw(), update(), swim();

private:
    float wiggle(int m);
    ofColor(healthyColor);
    
    //For movement
    float xoff, yoff;
    ofVec3f newVel;
};


#endif /* BigFish_hpp */
