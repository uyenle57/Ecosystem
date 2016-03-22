#pragma once
#include "ofMain.h"

#include "Organism.hpp"
#include "Worms.hpp"
#include "Leeches.hpp"
#include "Mosquitoes.hpp"

#include "DNA.hpp"
#include "Animals.hpp"
#include "Frogs.hpp"
#include "babyFrog.hpp"
#include "BigFish.hpp"
#include "babyFish.hpp"


class ofApp : public ofBaseApp {

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
    
    
    
    DNA parentDNA, childDNA;
    
    // ORGANISMS
    std::vector< unique_ptr<Organism>> organism;
    
    int numOrganisms = 3;
    
    shared_ptr<Worms> worms;
    shared_ptr<Leeches> leeches;
    shared_ptr<Mosquitoes> mosquitoes;
    
    // ANIMALS
    std::vector<unique_ptr<Animals>> animals;
    
    int numAnimals = 2;
    
    shared_ptr<Frogs> frogs;
    shared_ptr<BigFish> bigFish;
    
    shared_ptr<babyFrog> babyFrogs;
    shared_ptr<babyFish> babyFishes;
    
    void eat();
    void reproduce();
    void die();
};





