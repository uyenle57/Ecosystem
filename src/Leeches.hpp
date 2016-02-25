//
//  Leeches.hpp
//  cppUyen2
//
//  Created by Uyen Le on 21/02/2016.
//
//

#ifndef Leeches_hpp
#define Leeches_hpp

#include <stdio.h>
#include "Organism.hpp"


class Leeches: public Organism {
    
public:
    Leeches();
    ~Leeches();
    
    void draw(), swim(), movement(), mate();

};
#endif /* Leeches_hpp */
