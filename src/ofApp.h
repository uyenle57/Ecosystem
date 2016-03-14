#pragma once
#include "ofMain.h"

#include "Organism.hpp"
#include "Worms.hpp"
#include "Leeches.hpp"
#include "Mosquitoes.hpp"

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
    
    
    ofImage backgroundImg;
    
    // ORGANISM OBJECTS ----------------------------------------------------
    //std::vector <std::unique_ptr <Organism>> organism;
    //unique_ptr objects automatically delete the object (using a deleter) as soon as they themselves are destroyed, or as soon as their value changes either by an assignment operation or by an explicit call to unique_ptr::reset.
    
    std::vector<Organism *> organism;
    
    int numOrganisms = 5;
    
    Worms *worms;
    Leeches *leeches;
    Mosquitoes *mosquitoes;
    
    
    // ANIMAL OBJECTS ----------------------------------------------------
    std::vector<Animals *> animals;
    
    int numAnimals = 5;
    int numSmallFish = 50;
    
    Frogs *frogs;
    BigFish *bigFish;
    vector <SmallFish> smallFish;
    //SmallFish *smallFish;
};





