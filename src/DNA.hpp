//
//  DNA.hpp
//  cppUyen2
//
//  Created by Uyen Le on 20/03/2016.
//
//  The population of each Animal is based on their genetic information (DNA)
//  which defines how the animal looks or behaves
//  with reference from Nature of Code's Chapter 9

#ifndef DNA_hpp
#define DNA_hpp
#include "ofMain.h"
#include <stdio.h>


//DNA determines:
//Genotype: speed, weight of force (bigger => slower)
//          longer they survive => higher chance of reproduction
//Phenotype: bodysize

class DNA {

public:
    DNA();
    DNA(const DNA &dna);    //Use copy constructor for reproduction
    
    std::vector <float> genes;
    
    DNA crossover(DNA &partner);
    void mutate(float prob);
};

#endif /* DNA_hpp */
