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
    BigFish(float bigFishX, float bigFishY, float bigFishZ, DNA &dna);
    
    ~BigFish();
    
    void draw(), update(), swim(), eat();

private:
    float wiggle(int m);
    
    ofColor(bodyColor);
    ofColor(tailColor);
    
    //For movement
    float xoff, yoff;
};


#endif /* BigFish_hpp */
