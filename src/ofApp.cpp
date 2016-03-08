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


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);

    backgroundImg.load("background.jpg");
    backgroundImg.resize(ofGetWindowWidth(), ofGetWindowHeight());
    
    
    //Create Organisms
    for(int i=0; i < numOrganisms; i++) {
        worms = new Worms(ofGetWindowWidth()/2, ofRandom(ofGetWindowHeight()), ofRandom(-150,150));
        leeches = new Leeches(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(-150,150));
        mosquitoes = new Mosquitoes(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(-150,150));
        
        organism.push_back(worms);
        organism.push_back(leeches);
        organism.push_back(mosquitoes);
    }
}

//--------------------------------------------------------------
void ofApp::update() {
    for (auto & organism : organism) {
        organism->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    ofBackground(255);
    //backgroundImg.draw(0, 0);
    
    for (auto & organism : organism) {
        organism->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    //TO DO
    //simplify code
    //limit number of organisms that user can add before program lags
    
    //add new Organism if user presses keys w,l,m
//    for (auto & organism : organism) {
//        organism->keyPressed(key);
//    }
    
    if (key == 'w') {
        cout << "new worm" << endl;
        for(int i=0; i < 1; i++) {
            worms = new Worms(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(-150,150));
            organism.push_back(worms);
        }
    }
    
    if (key == 'l') {
        cout << "new leech" << endl;
        for(int i=0; i < 1; i++) {
            leeches = new Leeches(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(-150,150));
            organism.push_back(leeches);
        }
    }
    
    if (key == 'm') {
        cout << "new mosquito" << endl;
        for(int i=0; i < 1; i++) {
            mosquitoes = new Mosquitoes(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(-150,150));
            organism.push_back(mosquitoes);
        }
    }
}

//--------------------------------------------------------------
void ofApp::exit() {
    //delete dynamically allocated pointers upon exiting the program to free up space
    delete worms;
    delete leeches;
    delete mosquitoes;
    std::cout << "exited" << std::endl;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
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
