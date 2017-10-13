//
// Created by cjlon on 10/2/2017.
//

#ifndef CSE321_PROJECT_1_DRONE_H
#define CSE321_PROJECT_1_DRONE_H

#include "mingw.thread.h"
class Drone{
private:
        int _speed;
public:
    Drone(int speed);
    Drone& operator=(const Drone& other){
        _speed=other._speed;

    }
    int getSpeed();
};
#endif //CSE321_PROJECT_1_DRONE_H