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

    //Load background image
    backgroundImg.load("background.jpg");
    backgroundImg.resize(ofGetWindowWidth(), ofGetWindowHeight());
    
    //Create Organisms
    for(int i=0; i < 5; i++) {
        worms.push_back(Worms(ofGetWindowWidth()/2*i, ofRandom(50,ofGetWindowHeight()-100), 0));
        leeches.push_back(Leeches(ofRandom(100,ofGetWindowWidth()-100)*(i*0.4), ofRandom(100,ofGetWindowHeight()-100), 0));
        mosquitoes.push_back(Mosquitoes(ofGetWindowWidth()/2*(i*0.8), ofRandom(50,ofGetWindowHeight()-100), 0));
    }
    
// probably need this for adding new organisms
//    for(int i=0; i < 5; i++) {
//        organism1.push_back(unique_ptr<Organism>(new Worms(ofGetWindowWidth()/2*i, ofRandom(50,ofGetWindowHeight()-100), 0)));
//    }
}

//--------------------------------------------------------------
void ofApp::update(){

    // TODO: Better way to call same class function without repeating???
    for (auto & w: worms)  {
        w.update();
    }
    for (auto & l: leeches)  {
        l.update();
        //l.swim(mouseX, mouseY); //TODO
    }
    for (auto & m: mosquitoes)  {
        m.update();
    }
    
//    for (auto & org1 : organism1) { organism1.update(); } //error
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(255);
    //backgroundImg.draw(0, 0);
    
    for (auto & w: worms)  {   w.draw();   }
    for (auto & l: leeches)  {   l.draw();   }
    for (auto & m: mosquitoes)  {   m.draw();   }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    // TODO: fix add new organisms
    if (key == 'w'){
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
