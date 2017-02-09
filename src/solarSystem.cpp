//
//  solarSystem.cpp
//  myPlanet
//
//  Created by Jaehun Heo on 08/02/2017.
//
//

#include "solarSystem.hpp"

SolarSystem::SolarSystem(){
    Planet* planet_instance = new Planet();
    planets.push_back(planet_instance);
    selected_planet_id = 0;
}

SolarSystem::~SolarSystem(){
    do {
        Planet* selected = planets.back();
        delete selected;
        planets.pop_back();
        
    }while(planets.size() == 0);
}

void SolarSystem::addPlanet(){
    Planet* parent_planet = planets[selected_planet_id];
    vector<Planet*> brothers = parent_planet->getChildren();
    float min_distance;
    float max_distance;
    
    if (brothers.size()==0) {
        min_distance = 20;
        max_distance = 50;
    }
    else {
        float brother_distance = brothers.back()->getDistance();
        min_distance = brother_distance*1.5;
        max_distance = min_distance*1.8;
    }
    Planet* planet_instance = new Planet(parent_planet, ofRandom(min_distance, max_distance));
    planets.push_back(planet_instance);
    parent_planet->setChild(planet_instance);
}

void SolarSystem::selectNextPlanet(){
    selected_planet_id++;
    if (selected_planet_id >= planets.size()) {
        selected_planet_id = 0;
    }
}

void SolarSystem::selectPreviousPlanet(){
    selected_planet_id--;
    if (selected_planet_id < 0) {
        selected_planet_id = planets.size()-1;
    }
}

void SolarSystem::deletePlanet(){
    Planet* selected = planets.back();
    delete selected;
    planets.pop_back();
}

void SolarSystem::changeCenter(){
    
}

void SolarSystem::update(){
    for (int i = 0; i < planets.size(); i++){
        planets[i]->update();
    }
}

void SolarSystem::draw(){
    for (int i = 0; i < planets.size(); i++){
        ofVec2f planet_pos = planets[i]->getPosition();
        float planet_size = planets[i]->getSize();
        if (i == selected_planet_id) {
            ofSetColor(0, 255, 0);
        }
        else {
            ofSetColor(100, 100, 100);
        }
        ofDrawCircle(planet_pos, planet_size);
    }
}

vector<ofVec2f> SolarSystem::getAllPosition(){

}

int SolarSystem::getSelectedPlanetId(){
    return selected_planet_id;
}
