#pragma once
#include "ofMain.h"

#include "Organism.hpp"
#include "Worms.hpp"
#include "Leeches.hpp"
#include "Mosquitoes.hpp"

#include "Animals.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
    
    // Organism derived classes and their variables + functions -------------------
    deque <Worms> worms;
    deque <Leeches> leeches;
    deque <Mosquitoes> mosquitoes;
        
    void addWorm(), addLeech(), addMosquito();
    
    // Animals derived classes and their variables + functions -------------------
    
};
