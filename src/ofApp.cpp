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
#include "babyFrog.hpp"
#include "BigFish.hpp"
#include "babyFish.hpp"


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);

    //Create Organisms
    for(int i=0; i< numOrganisms; i++) {
        organism.push_back(unique_ptr<Organism>(new Worms(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0)));
        organism.push_back(unique_ptr<Organism>(new Leeches(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0)));
        organism.push_back(unique_ptr<Organism>(new Mosquitoes(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0)));
    }

    //Create Animals
    for (int i=0; i < numAnimals; i++) {
        babyFrogs.push_back(babyFrog(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, dna));
        babyFishes.push_back(babyFish(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, dna));
        
        animals.push_back(unique_ptr<Animals>(new Frogs(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, dna)));
        animals.push_back(unique_ptr<Animals>(new BigFish(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, dna)));
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
    
    /// just to see the animals
    for (auto & bfrog: babyFrogs) {
        bfrog.draw();
    }
    for (auto & bfish: babyFishes) {
        bfish.draw();
    }
}

//--------------------------------------------------------------
void ofApp::eat() {
    
    // TO DO: FIX DELETING ORGANISMS
    
    //declare nex vector for indices
    vector<unique_ptr<Organism>>::iterator iter;
    vector<int> indexes;
    
    for(int i=0; i < organism.size(); i++) {
        ofVec3f foodlocation = organism[i]->getPos(); //Organisms are food sources
        
        indexes.push_back(i);   //vector<index> pushback(i)
        
        for(int j=0; j < animals.size(); j++) {
            float dist = animals[j]->mPosition.distance(foodlocation);
            
            //If Animal is touching any food
            if (dist < 50) {
                if (animals[j]->mHealth <= 200) { //increase health
                    animals[j]->mHealth += 5;
                    cout << animals[j]->mHealth << endl;
                }
                //Delete organism at its index position
                for(int i=0; i < organism.size(); i++) {
                    organism.erase(organism.begin());   //+indexes[i]
                }
                //                for(iter=organism.begin(); iter != organism.end(); iter++) {
                //                    organism.erase(iter);
                //                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::reproduce() {
   
    for (auto & animals : animals) {
    //Only reproduce if the Animal is healthy
    if (animals->mHealth >= 130 && animals->mHealth <= 200) {
        if (ofRandom(1) < 0.05) { //small chance of reproduction
            DNA childDNA = dna; //create childDNA which is a copy of parent DNA
            childDNA.mutate(0.01);
            
            // TO DO
            //Check that if any two animals of the same species are close to each other
            //ofVec3f frogPos = frogs->mPosition;
            //ofVec3f fishPos = bigFish->mPosition;
            
            //float frogDist = frogPos.distance(otherFrog);
            //float fishDist = bigFish.distance(otherFish);
            
            //if (frogDist < 50) {
            // create a new child at that position
            // for(int i=0; i < 1; i++) {
            //  animals.push_back(unique_ptr<Animals>(new babyFrogs(ofRandom(frogDist, frogDist, 0, childDNA)));
            //}
            //}
            
            //repeat for fish
            
        
            }
        }
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
    
    //just to see the animals
    for (auto & bfrog: babyFrogs) {
        bfrog.update();
    }
    for (auto & bfish: babyFishes) {
        bfish.update();
    }
    
    ofApp::eat();
    ofApp::reproduce();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    // ADDING NEW ORGANISM WITH KEYPRESS
    if (key == 'w')
        for(int i=0; i < 1; i++) {
            organism.push_back(unique_ptr<Organism>(new Worms(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0)));
        }
    if (key == 'l')
        for(int i=0; i < 1; i++) {
            organism.push_back(unique_ptr<Organism>(new Leeches(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0)));
        }
    if (key == 'm')
        for(int i=0; i < 1; i++) {
            organism.push_back(unique_ptr<Organism>(new Mosquitoes(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0)));
        }
}

//--------------------------------------------------------------
void ofApp::exit() {
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
