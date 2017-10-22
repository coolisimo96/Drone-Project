//
// Created by cjlon on 10/12/2017.
//
#include "Coordinate.h"
/*
 * Constructs a coordinate, a unit which may be "occupied" by exactly one drone and is categorized by what it
 * describes(see comment for setCategory)
 */
Coordinate::Coordinate(int x, int y){
    _x=x;
    _y=y;
}
Coordinate::Coordinate() {
    _x=0;
    _y=0;
}

/*
 * Returns x value of Coordinate
 */
int Coordinate::getX(){
    return _x;
}
/*
 * Returns y value of Coordinate
 */
int Coordinate::getY(){
    return _y;
}

int Coordinate::getCount(){
   return _count;
}
void Coordinate::addCount(){
    _count=_count +1;
}
int Coordinate::getCategory() {
    return _category;
}
void Coordinate::setCategory(int cat) {
    _category=cat;
}
void Coordinate::unlockLoc() {
    _occupied.unlock();
}
/*
 * Attempts to lock a drone to the coordinate, or returns false if a drone is already located there
 */
bool Coordinate::occupySpace(){
    _isOccupied=true;
    return _occupied.try_lock();
}
bool Coordinate::getOcc() {
    return _isOccupied;
}