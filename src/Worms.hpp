//
//  Worms.hpp
//  cppUyen2
//
//  Created by Uyen Le on 21/02/2016.
//
// Derived Organism 1

#ifndef Worms_hpp
#define Worms_hpp

#include <stdio.h>
#include "Organism.hpp"

class Worms: public Organism {
    
    
public:
    Worms();
    ~Worms();
    
    void draw(), swim(), movement(), mate();
    void borders();
    
    void run();
    
private:
    
};

#endif /* Worms_hpp */
