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
void Drone::setDestination(Coordinate& newDest){
    _destination = newDest;
}
void Drone::setLoctation(Coordinate& newLoc){
    _location = newLoc;
}
void Drone::isUsing() {
    _inUse=true;
}
void Drone::loadDrone(bool flag) {
    _hasPayLoad = flag;
}
void Drone::gettingPayload(bool flag) {
    _gettingPayload=flag;
}
bool Drone::isGettingPayload(){
    return _gettingPayload;
}
bool Drone::isInuse() {
    return _inUse;
}
bool Drone::hasPayload() {
    return _hasPayLoad;
}
