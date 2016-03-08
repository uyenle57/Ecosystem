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


class Mosquitoes : public Organism{
    
public:
    Mosquitoes(float MosPosX, float MosPosY, float MosPosZ);
    //~Mosquitoes();
    
    void draw(), swim(), update();
    virtual void keyPressed(int key);
    
private:
    float flappyWings();
    
};

#endif /* Mosquitoes_hpp */
