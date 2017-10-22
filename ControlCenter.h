//
// Created by cjlon on 10/2/2017.
//

#ifndef CSE321_PROJECT_1_CONTROLCENTER_H
#define CSE321_PROJECT_1_CONTROLCENTER_H


#include "Drone.h"
#include <vector>
#include "Coordinate.h"
using namespace std;

class ControlCenter{
private:
    int _x,_y;
    vector<Drone> _drones;
    vector<vector<Coordinate>> _map;
    vector<Coordinate> _taskList;
    vector<Coordinate> _hoverList;
    bool isDroneSpot(int i, int j);
public:
    ControlCenter(int x,int y);
    ~ControlCenter();

    void registerDrones(vector<Drone>& drones);
    void generateTaskList(int x, int y);
    void generateHoverList(int x,int y);
    void printMap();
    vector<Coordinate> getHoverList();
    Coordinate& assignTask();
    void moveDrones(int i);
    void moveDronesHelper(int index, int direction);
};
#endif //CSE321_PROJECT_1_CONTROLCENTER_H