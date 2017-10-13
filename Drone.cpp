//
// Created by cjlon on 10/2/2017.
//
#include "Drone.h"
/*
 * Creates a drone which moves with a random speed, between 1 unit per move and 3
 */
Drone::Drone(int speed) {
    _speed = rand()%3+1;
}
/*
 * Returns the speed of the drone
 */
int Drone::getSpeed(){
    return _speed;
}

