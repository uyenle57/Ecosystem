//
//  Tadpoles.hpp
//  cppUyen2
//
//  Created by Uyen Le on 25/02/2016.
//
//

#ifndef Tadpoles_hpp
#define Tadpoles_hpp

#include <stdio.h>
#include "Organism.hpp"


class Tadpoles: public Organism {
   
public:
    Tadpoles(float posx, float posy, float posz);
    ~Tadpoles();
    
    void draw(), swim(vector<Tadpoles> neighbors), movement(), borders();
    void run();
    
};

#endif /* Tadpoles_hpp */
