//
// Created by cjlon on 10/12/2017.
//

#ifndef CSE321_PROJECT_1_COORDINATE_H
#define CSE321_PROJECT_1_COORDINATE_H

#include "mingw.mutex.h"
using namespace std;
class Coordinate{
private:
    mutex _occupied;
    int _x;
    int _y;
    int _z;
    int _category;
public:
    Coordinate(int x, int y, int z);
    Coordinate(const Coordinate& other){
        _x=other._x;
        _y=other._y;
        _z=other._y;
    }
    Coordinate& operator=(const Coordinate &other) {
        _x=other._x;
        _y=other._y;
        _z=other._z;
    }
    int getX();
    int gety();
    int getz();
    int getCategory();
    bool occupySpace();
    /*
     * Sets the category of the coordinate
     * 0=Center
     * 1=Drop Off Point
     * 2=Hover Point
     */
    void setCategory(int cat);
};
#endif //CSE321_PROJECT_1_COORDINATE_H
