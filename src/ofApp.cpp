#include "ofApp.h"
#include "ofMain.h"
#include <vector>
using std::vector;
using namespace std;

#include "Organism.hpp"
#include "Worms.hpp"
#include "Leeches.hpp"
#include "Tadpoles.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //Create 100 tadpoles
    for(int i=0; i < 100; i++) {
        tadpoles.push_back(Tadpoles(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), ofRandom(-50,50) ));
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    worm.run();
    leech.swim();
    
    for(auto & t: tadpoles) {
        t.update();
        t.swim(Tadpoles);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor centerColor = ofColor(85, 78, 68);
    ofColor edgeColor(255,255,255,50);
    //ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    ofBackground(255);
    
    worm.draw();
    leech.draw();
    
    for (auto & t: tadpoles) {
        t.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
