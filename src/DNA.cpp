//
//  DNA.cpp
//  cppUyen2
//
//  Created by はな on 20/03/2016.
//
//

#include "DNA.hpp"


DNA::DNA() {
    for(int i=0; i < 1; i++) { //Create array of DNA of length 1
        genes.push_back(i);
    }
    for(int i=0; i < genes.size(); i++) {  //Make a random DNA
        genes[i] = ofRandom(1); //DNA is a random float with values between 0 and 1
    }
}

//Copy the DNA
//------------------------------------------------------------------------
DNA::DNA(const DNA &dna) {
    
    vector<float> newgenes;
    newgenes = dna.genes;
    
    for (int i=0; i < dna.genes.size(); i++) {
        newgenes[i] = dna.genes[i];
    }
}

//------------------------------------------------------------------------
DNA DNA::crossover(DNA &partner) {
    DNA child;  //Create a child which is a new instance of DNA
    
    int midPoint = int(ofRandom(genes.size())); //Pick a random midpoint in the genes array
    
    for(int i=0; i < genes.size(); i++) {
        if (i > midPoint)
            child.genes[i] = genes[i];  //before midpoint, copy from parent A
        else
            child.genes[i] = partner.genes[i];  //after midpoint, copy from parent B
    }
    return child;
}

//------------------------------------------------------------------------
void DNA::mutate(float prob) {
    for (int i=0; i < genes.size(); i++) {
        if (ofRandom(1) < prob)      //Mutation based on probability of 1%
            genes[i] = ofRandom(1);  //pick a new random character
    }
}


