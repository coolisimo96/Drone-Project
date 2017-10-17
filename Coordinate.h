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
    int _category;
public:
    Coordinate();
    Coordinate(int x, int y);
    int getX();
    int getY();
    int getCategory();
    bool occupySpace();

    bool operator==(Coordinate& rhs)const{
        if((rhs.getX()==_x)&&(rhs.getY()==_y)){
            return true;
        }
        else{return false;}
    }
    Coordinate(const Coordinate& other){
        _x=other._x;
        _y=other._y;
        _category=other._category;
    }
    Coordinate& operator=(const Coordinate &other) {
        _x=other._x;
        _y=other._y;
    }
};

#endif //CSE321_PROJECT_1_COORDINATE_H
