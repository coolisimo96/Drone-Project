//
// Created by cjlon on 10/2/2017.
//

#ifndef CSE321_PROJECT_1_CONTROLCENTER_H
#define CSE321_PROJECT_1_CONTROLCENTER_H

#endif //CSE321_PROJECT_1_CONTROLCENTER_H
class Coordinate{
private:
    int _x;
    int _y;
    int _z;
public:
    Coordinate(int x,int y, int z){
        _x=x;
        _y=y;
        _z=z;
    }
    int getX(){
        return _x;
    }
    int gety(){
        return _y;
    }
    int getz(){
        return _z;
    }
};
class ControlCenter{
public:
    ControlCenter(int x,int y);

    ~ControlCenter();

    void assignTask();

    void registerDrone();

    Coordinate* generateTaskList(Coordinate* first,int x, int y);
};