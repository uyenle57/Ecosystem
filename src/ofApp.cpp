#include <vector>
#include <math.h>
using std::vector;
using namespace std;

#include "ofApp.h"
#include "ofMain.h"

#include "Organism.hpp"
#include "Worms.hpp"
#include "Leeches.hpp"
#include "Mosquitoes.hpp"

#include "Animals.hpp"
#include "Frogs.hpp"
#include "BigFish.hpp"
#include "SmallFish.hpp"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);

    //Create Organisms
    for(int i=0; i < numOrganisms; i++) {
        worms = new Worms(ofGetWidth()/2, ofRandom(ofGetHeight()), 0);
        leeches = new Leeches(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
        mosquitoes = new Mosquitoes(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0);
        
        organism.push_back(worms);
        organism.push_back(leeches);
        organism.push_back(mosquitoes);
    }
    
    //Create Animals
    for (int i=0; i < numAnimals; i++) {
        frogs = new Frogs(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, dna);
        bigFish = new BigFish(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, dna);
        
        animals.push_back(frogs);
        animals.push_back(bigFish);
    }
    
    //Create small fish seperately because there needs to be much more small fishes for flocking
    for (int i=0; i < numSmallFish; i++) {        
        smallFish = new SmallFish(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, dna);
        animals.push_back(smallFish);
    }
    
}

//--------------------------------------------------------------
void ofApp::update() {
    for (auto & organism : organism) {
        organism->update();
    }
    for (auto & animals : animals) {
        animals->update();
    }
    
    // HOW TO EAT ------------------------------------------
    // TO DO: move this to Animals class ??
    for (auto & organism : organism) {
        ofVec3f foodlocation = organism->getPos();  //Organisms are food sources
        
        for(auto & animals : animals) {
            float dist = animals->mPosition.distance(foodlocation);
            
            if (dist < 50/2) {              //Check if the Animal is close to any organism
                if (animals->mLifespan <= 200) {
                    animals->mLifespan += 5;  //if so, increase lifespan
                    cout << animals->mLifespan << endl;
                }
                organism->~Organism();      //and kill that organism
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    //Background gradient
    ofColor colorOne(255);
    ofColor colorTwo(155, 220, 247);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
    
    for (auto & organism : organism) {
        organism->draw();
    }
    for (auto & animals : animals) {
        animals->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    //TO DO: limit number of organisms that user can add before program lags (50)
    if (key == 'w')
        for(int i=0; i < 1; i++) {
            worms = new Worms(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), 0);
            organism.push_back(worms);
        }
    if (key == 'l')
        for(int i=0; i < 1; i++) {
            leeches = new Leeches(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), 0);
            organism.push_back(leeches);
        }
    if (key == 'm')
        for(int i=0; i < 1; i++) {
            mosquitoes = new Mosquitoes(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), 0);
            organism.push_back(mosquitoes);
        }
}

//--------------------------------------------------------------
void ofApp::exit() {
    
    //Delete all objects upon exiting the program
    for (auto & organism: organism) {
        organism->~Organism();
    }
    for (auto & animals : animals) {
        animals->~Animals();
    }
    std::cout << "========= GAME CLOSED ==========" << std::endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
