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

// HOW ANIMALS EAT ORGANISMS
//--------------------------------------------------------------
void ofApp::eat() {
    
    for(int i=0; i < organism.size(); i++) {
        ofVec3f foodlocation = organism[i]->getPos(); //Organisms are food sources
        
        for(int j=0; j < animals.size(); j++) {
            
            //If Animal is touching any food
//            float dist = animals[j]->mPosition.distance(foodlocation);
//            float sumRadii = organism[i]->mSize + animals[j]->mSize;
//            
//            if (dist < sumRadii) {
//                if (animals[j]->mHealth >= 0 && animals[j]->mHealth <= 200) { //increase health within boundaries of 0-200
//                    animals[j]->mHealth += 5;
//                }
//                //Delete organism at its index position
//                organism.erase(organism.begin()+i);
//            }
        }
    }
}

// HOW TO REPRODUCE
//--------------------------------------------------------------
void ofApp::reproduce() {

    for (int i=0; i < animals.size(); i++) {
    
        if (ofRandom(1) < animals[i]->birthRate) { //small chance of reproduction
        
            //Only reproduce if the Animal is healthy
            if (animals[i]->mHealth >= 130 && animals[i]->mHealth <= 200) {
        
                //create childDNA which is a copy of parent DNA
                DNA childDNA = parentDNA.crossover(parentDNA);
                childDNA.mutate(animals[i]->mutateRate);
                
                for (int j=0; j < animals.size(); j++) {
                    
                    //check that animals of the same species are close to each other
                    float dist = animals[i]->mPosition.distance(animals[j]->mPosition);
                    float sumRadii = animals[i]->mSize + animals[j]->mSize;
                    
                    if (dist < sumRadii) {
                        
                    ofVec3f babyAnimalPos = animals[i]->getPos();
                    
                    //Give birth to baby Frogs at the location of parent Frogs with a very low chance of reproduction
                    if (ofRandom(1) < animals[i]->birthRate) {
                        if (animals[i]->species == "Frog" && animals[j]->species == "Frog") {
                         animals.push_back(unique_ptr<Animals>(new babyFrog(babyAnimalPos.x, babyAnimalPos.y, babyAnimalPos.z, childDNA)));
                        }
                    }
                    
                    //do the same for Fish reproduction
                    if (ofRandom(1) < animals[i]->birthRate) {
                        if (animals[i]->species == "Fish" && animals[j]->species == "Fish") {
                        animals.push_back(unique_ptr<Animals>(new babyFish(babyAnimalPos.x, babyAnimalPos.y, babyAnimalPos.z, childDNA)));
                        }
                    }
                    }
                }
            }
        }
    }
}

// HOW ANIMALS DIE (if run out of food)
//--------------------------------------------------------------
void ofApp::die() {
    
    for (int i=0; i < animals.size(); i++) {
        if (animals[i]->isDead()) {
            animals.erase(animals.begin());
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
    ofApp::die();
}

// ADDING NEW ORGANISM WITH KEYPRESS
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
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
