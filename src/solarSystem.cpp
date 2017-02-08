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
}

SolarSystem::~SolarSystem(){
    do {
        Planet* selected = planets.back();
        delete selected;
        planets.pop_back();
        
    }while(planets.size() == 0);
}

void SolarSystem::addPlanet(){
    Planet* parent_planet = planets.back();
    Planet* planet_instance = new Planet(parent_planet);
    planets.push_back(planet_instance);
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
        ofDrawCircle(planet_pos, planet_size);
    }
}

vector<ofVec2f> SolarSystem::getAllPosition(){

}
