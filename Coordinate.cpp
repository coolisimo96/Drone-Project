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
/*
 * Returns category of Coordinate
 */
int Coordinate::getCategory(){
    return _category;
}
/*
 * Attempts to lock a drone to the coordinate, or returns false if a drone is already located there
 */
bool Coordinate::occupySpace(){
    return _occupied.try_lock();
}
