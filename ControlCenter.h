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
    vector<Drone> _Drones;
    vector<vector<vector<Coordinate>>> _map;
    vector<Coordinate> _taskList;
    vector<Coordinate> _hoverList;
public:
    ControlCenter(int x,int y);

    ~ControlCenter();

    Coordinate assignTask();

    void registerDrone(Drone newDrone);

    void generateTaskList(int x, int y);
    void generateHoverList(int x,int y);
    vector<Coordinate> getTaskList();

    vector<Drone> getDrones();

};
#endif //CSE321_PROJECT_1_CONTROLCENTER_H