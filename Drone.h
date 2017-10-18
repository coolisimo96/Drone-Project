//
// Created by cjlon on 10/2/2017.
//

#ifndef CSE321_PROJECT_1_DRONE_H
#define CSE321_PROJECT_1_DRONE_H

#include "mingw.thread.h"
#include "Coordinate.h"
class Drone{
private:
        Coordinate _destination;
        Coordinate _location;
public:
    Drone();
    Drone(const Drone& other){
        _destination=other._destination;
        _location=other._location;
    }
    Drone& operator=(const Drone& other){
        _destination=other._destination;
        _location=other._location;
    }
    Coordinate& getDestination();
    Coordinate& getLocation();
    void setLoctation(Coordinate newLoc);
    void setDestination(Coordinate newDest);
    Coordinate move();
};
#endif //CSE321_PROJECT_1_DRONE_H