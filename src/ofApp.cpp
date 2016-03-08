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
        worms = new Worms((ofGetWindowWidth()/2)*i, //x
                           ofRandom(ofGetWindowHeight()-100), //y
                           0); //z
        leeches = new Leeches(ofRandom(ofGetWindowWidth())*(i*0.4),
                              ofRandom(ofGetWindowHeight()),
                              0);
        mosquitoes = new Mosquitoes(ofGetWindowWidth()/2*(i*0.8),
                                    ofRandom(50,ofGetWindowHeight()-100), 0);
        
        organism.push_back(worms);
        organism.push_back(leeches);
        organism.push_back(mosquitoes);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
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

    //add new Organism if user presses keys w,l,m
    for (auto & organism : organism) {
        organism->keyPressed(key);
    }
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
