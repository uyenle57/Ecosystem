#pragma once
#include "ofMain.h"

#include "Organism.hpp"
#include "Worms.hpp"
#include "Leeches.hpp"
#include "Mosquitoes.hpp"

#include "DNA.hpp"
#include "Animals.hpp"
#include "Frogs.hpp"
#include "BigFish.hpp"
#include "SmallFish.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
        void exit();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
    
    // DNA
    DNA dna;
    
    // ORGANISMS ----------------------------------------------------
    std::vector<Organism *> organism;
    
    int numOrganisms = 4;
    
    Worms *worms;
    Leeches *leeches;
    Mosquitoes *mosquitoes;
    
    
    // ANIMALS ----------------------------------------------------
    std::vector<Animals *> animals;
    
    int numAnimals = 1; //2;
    int numSmallFish = 15;
    
    Frogs *frogs;
    BigFish *bigFish;
    SmallFish *smallFish;  

};





