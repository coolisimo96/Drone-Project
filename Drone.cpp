//
// Created by cjlon on 10/2/2017.
//
#include "Drone.h"
/*
 * Creates a drone which moves with a random speed, between 1 unit per move and 3
 */
Drone::Drone() {
    _destination;
}
/*
 * Returns the speed of the drone
 */
Coordinate& Drone::getDestination() {
    return _destination;
}
Coordinate& Drone::getLocation() {
    return _location;
}
void Drone::setDestination(Coordinate newDest){
    _destination = newDest;
}
void Drone::setLoctation(Coordinate newLoc){
    _location = newLoc;
}
Coordinate Drone::move() {

}
