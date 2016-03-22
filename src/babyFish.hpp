//
//  babyFish.hpp
//  cppUyen2
//
//  Created by はな on 21/03/2016.
//
//

#ifndef babyFish_hpp
#define babyFish_hpp

#include <stdio.h>
#include "BigFish.hpp"


class babyFish : public BigFish {
    
public:
    babyFish(float babyFishX, float babyFishY, float babyFishZ, DNA &dna);
    
    ~babyFish();
    
    void draw(), update();
    
    float mSize;
    
};



#endif /* babyFish_hpp */
