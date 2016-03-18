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
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);

    backgroundImg.load("background.jpg");
    backgroundImg.resize(ofGetWindowWidth(), ofGetWindowHeight());
    
    
    //Create Organisms
    for(int i=0; i < numOrganisms; i++) {
        worms = new Worms(ofGetWidth()/2, ofRandom(ofGetHeight()), ofRandom(-150,150));
        leeches = new Leeches(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-150,150));
        mosquitoes = new Mosquitoes(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-150,150));
        
        organism.push_back(worms);
        organism.push_back(leeches);
        organism.push_back(mosquitoes);
    }
    
    //Create Animals
    for (int i=0; i < numAnimals; i++) {
        frogs = new Frogs(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-100,100));
        bigFish = new BigFish(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-100,100));
        
        animals.push_back(frogs);
        animals.push_back(bigFish);
    }
    for (int i=0; i < numSmallFish; i++) {
        smallFish.push_back(SmallFish(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-100,100)));
        //smallFish = new SmallFish(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-100,100));
        //animals.push_back(smallFish);
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (auto & organism : organism) {
        organism->update();
    }
    for( auto & smallfish : smallFish) {
        smallfish.update();
        smallfish.addAttraction(smallfish);
        //smallfish.moveAwayFromMouse(mouseX, mouseY, 40, 0.5);
    }
    
    for (auto & animals: animals) {
        animals->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(255);
    //backgroundImg.draw(0, 0);
    
    for (auto & organism : organism) {
        organism->draw();
    }
    for (auto & animals: animals) {
        animals->draw();
    }
//    for (auto & smallfish : smallFish) {
//        smallfish.draw();
//    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    //TO DO: limit number of organisms that user can add before program lags (50)
    if (key == 'w')
        cout << "new worm added" <<  endl;
        for(int i=0; i < 1; i++) {
            worms = new Worms(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(-150,150));
            organism.push_back(worms);
        }
    if (key == 'l')
        cout << "new leech added" << endl;
        for(int i=0; i < 1; i++) {
            leeches = new Leeches(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(-150,150));
            organism.push_back(leeches);
        }
    if (key == 'm')
        cout << "new mosquito added" << endl;
        for(int i=0; i < 1; i++) {
            mosquitoes = new Mosquitoes(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(-150,150));
            organism.push_back(mosquitoes);
        }
}

//--------------------------------------------------------------
void ofApp::exit() {
    //delete dynamically allocated pointers upon exiting the program
    delete worms;
    delete leeches;
    delete mosquitoes;
    std::cout << "exited." << std::endl;
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
