#include "ofApp.h"
#include "ofMain.h"

#include "Organism.hpp"
#include "Worms.hpp"
#include "Leeches.hpp"
#include "Mosquitoes.hpp"

#include "Animals.hpp"

#include <vector>
using std::vector;
using namespace std;


//--------------------------------------------------------------
void ofApp::setup(){
    
    //Create 10 worms randomly throughout the screen
    for(int i=0; i < 5; i++) {
        worms.push_back(Worms(ofGetWindowWidth()/2*i, ofGetWindowHeight()/2, 0));
    }
    
    //Create 10 leeches
    //Create 10 mosquitoes
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (auto & w: worms)  {   w.update();   }
//    for (auto & l: Leeches)  {   l.update();   }
//    for (auto & m: Mosquitoes)  {   m.update();   }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofColor centerColor(85, 78, 68);
    ofColor edgeColor(255,255,255,50);
    //ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    ofBackground(255);
    
    for (auto & w: worms)  {   w.draw();   }
//    for (auto & l: Leeches)  {   l.draw();   }
//    for (auto & m: Mosquitoes)  {   m.draw();   }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'w'){
        cout << "new worms!" << endl;
        addWorm = new Worms(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), 0);
    }
    if (key == 'l') {
        
    }
    if (key == 'm'){
        
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
