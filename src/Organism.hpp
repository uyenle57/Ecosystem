//
//  Organism.hpp
//  cppUyen2
//
//  Created by Uyen Le on 16/02/2016.
//
// Base class Organism

#ifndef Organism_hpp
#define Organism_hpp

#include <stdio.h>
#include "ofMain.h"

class Organism {
    
public:
    //Organism(int posx, int posy, int posz);
    Organism();
    void Draw();
    void Move();
    
private:
    ofVec3f mPosition, velocity, acceleration, lifespan;
    
    int mPosx, mPosy, mPosz;
    
    ofColor(color);
    
protected:

//    void addOrganism();
    
    
};
#endif /* Organism_hpp */
