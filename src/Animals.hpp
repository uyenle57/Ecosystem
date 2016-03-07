//
//  Animals.hpp
//  cppUyen2
//
//  Created by Uyen Le on 26/02/2016.
//
//  Base class Animals

#ifndef Animals_hpp
#define Animals_hpp

#include <stdio.h>
#include "ofMain.h"


class Animals {
    
    //Variables: DNA, location, velocity, acceleration, lifespan (die if out of food).
    
    //Behaviours: eat, reproduce, collision detection, change body colour, die
    
    //probability of reproduction (+ reproduction rate)
    
    //derived animals: frogs, flock of small fish, big fish, snakes
    
    //Variables
    float mLifeSpan;
    
    ofVec3f mPosition, mVelocity, mAcceleration;
    

};
#endif /* Animals_hpp */
