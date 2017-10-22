//
// Created by cjlon on 10/2/2017.
//

#ifndef CSE321_PROJECT_1_DRONE_H
#define CSE321_PROJECT_1_DRONE_H

#include "Coordinate.h"
class Drone{
private:
    Coordinate _destination;
    Coordinate _location;
    bool _inUse=false;
    bool _hasPayLoad=false;
    bool _gettingPayload=true;
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
    void setLoctation(Coordinate& newLoc);
    void setDestination(Coordinate& newDest);
    void isUsing();
    void loadDrone(bool flag);
    void gettingPayload(bool flag);
    bool hasPayload();
    bool isInuse();
    bool isGettingPayload();
};
#endif //CSE321_PROJECT_1_DRONE_H