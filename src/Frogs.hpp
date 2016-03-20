//
//  Frogs.hpp
//  cppUyen2
//
//  Created by Uyen Le on 13/03/2016.
//
//

#ifndef Frogs_hpp
#define Frogs_hpp

#include <stdio.h>
#include "Animals.hpp"


class Frogs : public Animals {

public:
    Frogs(float frogPosX, float frogPosY, float frogPosZ, DNA &dna);
    
    ~Frogs();
    
    void draw(), update(), swim(); //eat();
    
private:
    ofColor(healthyColor);
    
    //For movement
    float xoff, yoff;
    ofVec3f newVel;
};


#endif /* Frogs_hpp */
