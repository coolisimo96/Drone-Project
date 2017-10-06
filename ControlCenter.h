//
// Created by cjlon on 10/2/2017.
//

#ifndef CSE321_PROJECT_1_CONTROLCENTER_H
#define CSE321_PROJECT_1_CONTROLCENTER_H


#include "Drone.cpp"
#include <vector>
using namespace std;

class Coordinate{
private:
    int _x;
    int _y;
    int _z;

public:
    Coordinate(int x, int y, int z){
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
private:
    vector<Drone> _Drones;
    vector<vector<vector<Coordinate>>> _map;
    vector<Coordinate> _taskList;
public:
    ControlCenter(int x,int y);

    ~ControlCenter();

    void assignTask();

    void registerDrone(Drone newDrone);

    void generateTaskList(int x, int y);

    vector<Coordinate> getTaskList();

    vector<Drone> getDrones();

};
#endif //CSE321_PROJECT_1_CONTROLCENTER_H