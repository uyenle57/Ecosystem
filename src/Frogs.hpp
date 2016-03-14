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
    Frogs(float frogPosX, float frogPosY, float frogPosZ);
    
    virtual ~Frogs();
    
    void draw(), update(), swim(), mate(), eat(), changeColor();
    
    //ofColor(bodyColor);

protected:
private:
    float flappyLegs();
};


#endif /* Frogs_hpp */
