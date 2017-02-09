//
//  planet.hpp
//  myPlanet
//
//  Created by Jaehun Heo on 08/02/2017.
//
//

#ifndef planet_hpp
#define planet_hpp

#include <iostream>
#include <stdio.h>
#include <ofMain.h>

class Planet{
public:
    Planet();
    Planet(Planet* _parent, float _distance=20);
    ~Planet();
    void setup();
    void setup(Planet* _parent);
    void update();
    void draw();
    
    bool isCenterOfWorld();
    
    void setChild(Planet* _child);
    
    int getId();
    float getDistance();
    Planet* getParent();
    vector<Planet*> getChildren();
    ofVec2f getPosition();
    float getSize();
    float getTheta();
    
private:
    bool center_of_the_world;
    int id;     // 본인 ID
    float distance;    // 부모와의 거리
    vector<Planet*> children;  // 자식들 인스턴스
    Planet* parent; // 부모 인스턴스
    
    ofVec2f parent_position;
    ofVec2f position;   // 현재 위치
    float theta; // 현재 각위치
    float speed; // 회전 속도
    float size;  // 크기
    
};

#endif /* planet_hpp */
