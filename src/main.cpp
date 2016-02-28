#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}

/*
 C++ Term 2 Project - Work In Progress
 Ecosystem Simulation by Uyen Le
 
 Created on Tues,16 Feb 2016.
*/

/*
Organisms are: worms, leeches, mosquitoes.
Animals are: frogs, squids, flock of small fish, big fish.
 
All organisms and animals eat and swim.
Organisms don't mate and eat. Only die when eaten (Destructor call).

Animals don't eat each other, only eat Organisms. Die when run out of organisms to eat (Destructor call).
 
Organisms' Destructor is called when it is eaten (free memory for new organisms to be added by User).
Animals' sign of hunger and death shown through change of colour: Hungry=green; Dying=red; Dead=fade away.
 
=> Gameplay: a visual simulation of the Ecosystem. Can either play or just watch.
    - Add new Organisms to feed the Animals (keypress)
    - If not all Animals will die and Organisms will takeover the ecosystem.
*/