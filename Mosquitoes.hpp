//
//  Mosquitoes.hpp
//  cppUyen2
//
//  Created by Uyen Le on 26/02/2016.
//
//  Derived Organism 3
//  Mosquitoes fly around: faster speed + Flapping wings


#ifndef Mosquitoes_hpp
#define Mosquitoes_hpp

#include <stdio.h>
#include "Organism.hpp"


class Mosquitoes {
    
public:
    Mosquitoes();
    ~Mosquitoes();
    
    void eat(), swim(), movement(), returnToScreen(), draw();
    void update();
};

#endif /* Mosquitoes_hpp */
