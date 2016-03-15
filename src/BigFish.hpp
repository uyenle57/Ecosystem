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
    ~BigFish();
    
    void draw(), update();

private:
    ofColor(healthyColor);

};


#endif /* BigFish_hpp */
