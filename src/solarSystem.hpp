//
//  solarSystem.hpp
//  myPlanet
//
//  Created by Jaehun Heo on 08/02/2017.
//
//
//  Planet들의 생성과 소멸, 움직임을 관장하는 클래스
//

#ifndef solarSystem_hpp
#define solarSystem_hpp

#include <stdio.h>
#include <ofMain.h>
#include <iostream>
#include "planet.hpp"

class SolarSystem{
public:
    SolarSystem();
    ~SolarSystem();
    void addPlanet();
    void selectNextPlanet();
    void selectPreviousPlanet();
    void deletePlanet();
    void changeCenter();
    void update();
    void draw();
    
    vector<ofVec2f> getAllPosition();
    int getSelectedPlanetId();
    
private:
    vector<Planet*> planets;
    int selected_planet_id;
    
};

#endif /* solarSystem_hpp */
