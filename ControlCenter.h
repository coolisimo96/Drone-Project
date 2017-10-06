//
// Created by cjlon on 10/2/2017.
//

#ifndef CSE321_PROJECT_1_CONTROLCENTER_H
#define CSE321_PROJECT_1_CONTROLCENTER_H


#include "Drone.h"
#include <vector>
using namespace std;

class Coordinate{
private:
    int _x;
    int _y;
    int _z;
    int _category;
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
    int getCategory(){
        return _category;
    }
    /*
     * Sets the category of the coordinate
     * 0=Center
     * 1=Drop Off Point
     * 2=Hover Point
     */
    void setCategory(int cat){
        _category=cat;
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