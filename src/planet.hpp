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
    Planet(int _parent_id, float _distance);
    ~Planet();
    void setup(int _parent_id = -1);
    void setup(int _parent_id, float _distance);
    void update();
    void draw();
    void setChild();
    
    int getId();
    int getParent();
    vector<int> getChildren();
    ofVec2f getPosition();
private:
    bool center_of_the_world;
    int id;     // 본인 ID
    float distance;    // 부모와의 거리
    int parent_id;    // 부모 ID
    vector<int> children_id;  // 자식들 ID
    Planet* parent_pointer;
    
    ofVec2f my_position;   // 현재 위치
    float my_theta; // 현재 각위치
    float my_size;  // 크기
    
};

#endif /* planet_hpp */
