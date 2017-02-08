//
//  planet.cpp
//  myPlanet
//
//  Created by Jaehun Heo on 08/02/2017.
//
//

#include "planet.hpp"

Planet::Planet(){
    
}

Planet::Planet(int _parent_id, float _distance){
    parent_id = _parent_id;
    distance = _distance;
    center_of_the_world = false;
    my_size = 5.0;
    my_position = ofVec2f(0, 0);
    my_theta = 0.0;
}

Planet::~Planet(){
    
}

void Planet::setup(int _parent_id){
    parent_id = _parent_id;
    distance = 0;
    center_of_the_world = true;
    my_size = 5.0;
    my_position = ofVec2f(0, 0);
    my_theta = 0.0;
    
}

void Planet::setup(int _parent_id, float _distance){
    
}

void Planet::update(){
    if (!center_of_the_world){
        
    }
}

void Planet::draw(){
    
}

void Planet::setChild(){
    
}

int Planet::getParent(){
    
}

vector<int> Planet::getChildren(){
    
}

ofVec2f Planet::getPosition(){
    
}
