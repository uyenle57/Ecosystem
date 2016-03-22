//
//  babyFrog.hpp
//  cppUyen2
//
//  Created by Uyen Le on 21/03/2016.
//
//  Baby Frog is exactly the same as big Frogs but has smaller body size

#ifndef babyFrog_hpp
#define babyFrog_hpp

#include <stdio.h>
#include "Frogs.hpp"


class babyFrog : public Frogs {
    
public:
    babyFrog(float babyFrogX, float babyFrogY, float babyFrogZ, DNA &dna);
    
    ~babyFrog();
    
    void draw(), update();
    
    float mSize;
     
};


#endif /* babyFrog_hpp */
