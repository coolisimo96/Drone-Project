//
// Created by cjlon on 10/2/2017.
//

#ifndef CSE321_PROJECT_1_DRONE_H
#define CSE321_PROJECT_1_DRONE_H

#include "mingw.thread.h"
#include "Coordinate.h"
class Drone{
private:
        int _speed;
public:
    Drone();
    Drone& operator=(const Drone& other){
        _speed=other._speed;
    }
    int getSpeed();
    Coordinate getDestination();
    void setDestination(Coordinate newDest);
};
#endif //CSE321_PROJECT_1_DRONE_H