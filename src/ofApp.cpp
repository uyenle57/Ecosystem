#include <vector>
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
    
    //Create Organisms
    for(int i=0; i < 5; i++) {
        worms.push_back(Worms(ofGetWindowWidth()/2*i, ofRandom(50,ofGetWindowHeight()-100), 0));
        //leeches.push_back(Leeches(ofGetWindowWidth()/2*i, ofRandom(50,ofGetWindowHeight()-100), 0));
        mosquitoes.push_back(Mosquitoes(ofGetWindowWidth()/2*i, ofRandom(50,ofGetWindowHeight()-100), 0));
    }
    for (int i=0; i<5; i++) {
        leeches.push_back(Leeches(ofGetWindowWidth()/2*i, ofRandom(50,ofGetWindowHeight()-100), 0));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //for (auto & w: worms)  {   w.update();   }
    for (auto & l: leeches)  {   l.update();   }
    //for (auto & m: mosquitoes)  {   m.update();   }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    ofColor centerColor(85, 78, 68);
    ofColor edgeColor(255,255,255,50);
    //ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);
    
    // TODO: Better way to repeat calling same class function???
    //for (auto & w: worms)  {   w.draw();   }
    for (auto & l: leeches)  {   l.draw();   }
    //for (auto & m: mosquitoes)  {   m.draw();   }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // TODO: fix add new organisms
    if (key == 'w'){
        newWorm = new Worms(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()), 0);
        std::cout << "new worms added" << std::endl;
    }
//    else if (key == 'x') {
//        delete newWorm;
//        cout << "worm deleted" << endl;
//    }
    if (key == 'l') {
        //
        std::cout << "new leeches added" << std::endl;
    }
    if (key == 'm'){
        //
        std::cout << "new mosquitoes added" << std::endl;
    }
}

//--------------------------------------------------------------
void ofApp::addWorm() {
    
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
