//
//  planet.cpp
//  myPlanet
//
//  Created by Jaehun Heo on 08/02/2017.
//
//

#define SPEED 0.01

#include "planet.hpp"

Planet::Planet(){
    // 최초의 행성을 만들 때 호출
    id = 0;
    parent = NULL;
    distance = 0;
    center_of_the_world = true;
    size = 10.0;
    position = ofVec2f(0, 0);
    theta = 0.0;
    speed = 0.1;
    period = 1.0;
    depth = 0;
}

Planet::Planet(Planet* _parent, float _distance){
    // 자식 행성 만들 때 호출
    parent = _parent;
    id = parent->getId() + 1;
    depth = parent->getDepth() + 1;
    distance = _distance;
    center_of_the_world = false;
    size = 5.0/depth;
    theta = 0.0;
    speed = ofRandom(0.1/distance, 0.5/distance);
    parent_position = parent->getPosition();
    position = parent_position + ofVec2f(distance*sin(theta), distance*cos(theta));
}

Planet::~Planet(){
    
}

void Planet::setup(){
    parent = NULL;
    distance = 0;
    center_of_the_world = true;
    size = 10.0;
    position = ofVec2f(0, 0);
    theta = 0.0;
}

void Planet::setup(Planet* _parent){
    
}

void Planet::update(){
    if (!center_of_the_world){
        parent_position = parent->getPosition();
        theta = theta + speed;
        position = parent_position + ofVec2f(distance * sin(theta), distance * cos(theta));
    }
    else{
        theta += SPEED;
    }
}

void Planet::draw(){
    
}

bool Planet::isCenterOfWorld(){
    return center_of_the_world;
}

void Planet::setChild(Planet* _child){
    children.push_back(_child);
}

int Planet::getId(){
    return id;
}

float Planet::getDistance(){
    return distance;
}

Planet* Planet::getParent(){
    return parent;
}

vector<Planet*> Planet::getChildren(){
    return children;
}

ofVec2f Planet::getPosition(){
    return position;
}

float Planet::getSize(){
    return size;
}

float Planet::getTheta(){
    return theta;
}

int Planet::getDepth(){
    return depth;
}
