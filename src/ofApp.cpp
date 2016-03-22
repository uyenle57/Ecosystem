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
        animals.push_back(unique_ptr<Animals>(new Frogs(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, parentDNA)));
        animals.push_back(unique_ptr<Animals>(new BigFish(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 0, parentDNA)));
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
   
    for (int i=0; i < animals.size(); i++) {
        
        if (ofRandom(1) < animals[i]->birthRate) { //small chance of reproduction
        
            //Only reproduce if the Animal is healthy
            if (animals[i]->mHealth >= 130 && animals[i]->mHealth <= 200) {
        
                //create childDNA which is a copy of parent DNA
                DNA childDNA = parentDNA.crossover(parentDNA); //dna;
                childDNA.mutate(animals[i]->mutateRate);

                // create a new child at that its parents' positions
                for(int i=0; i < 1; i++) {
                    animals.push_back(unique_ptr<Animals>(new babyFrog(animals[i]->mPosition.x, animals[i]->mPosition.y, animals[i]->mPosition.z, childDNA)));
                    animals.push_back(unique_ptr<Animals>(new babyFish(animals[i]->mPosition.x, animals[i]->mPosition.y, animals[i]->mPosition.z, childDNA)));
                }
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
void ofApp::update() {
    for (auto & organism : organism) {
        organism->update();
    }
    for (auto & animals : animals) {
        animals->update();
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
