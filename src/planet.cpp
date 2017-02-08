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
}

Planet::Planet(Planet* _parent){
    // 자식 행성 만들 때 호출
    parent = _parent;
    id = parent->getId() + 1;
    distance = 20;
    center_of_the_world = false;
    size = 5.0;
    theta = 0.0;
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
        theta = parent->getTheta()*2;   // <-------- 회전 속도 수정 필요
        position = parent_position + ofVec2f(distance*sin(theta), distance*cos(theta));
    }
    else{
        theta += SPEED;
    }
}

void Planet::draw(){
    
}

void Planet::setChild(){
    
}

int Planet::getId(){
    return id;
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
