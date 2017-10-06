//
// Created by cjlon on 10/2/2017.
//
#include <iostream>
#include "ControlCenter.h"
using namespace std;

ControlCenter::ControlCenter(int x, int y) {
    int flag=0;

    for(int i=0;i<x;i++){
        _map.emplace_back(vector<vector<Coordinate>>());
        for(int j=0;j<y;j++){
            _map[i].emplace_back(vector<Coordinate>());
            for(int k=0;k<4;k++){
                _map[i][j].emplace_back(new Coordinate(i,j,k));
            }
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(i==0 || i==x-1 || j==0 || j==y-1){
                _taskList.emplace_back( _map[j][i][0]);
                cout << _taskList[flag].getX() << ","<<_taskList[flag].gety()<<std::endl;
                ++flag;
            }
        }
    }

}

vector<Coordinate> ControlCenter::getTaskList() {
    return _taskList;
}
void ControlCenter::assignTask() {

}
void ControlCenter::generateTaskList(int x, int y) {

}
void ControlCenter::registerDrone(Drone newDrone) {
    _Drones.push_back(newDrone);
}
vector<Drone> ControlCenter::getDrones(){
    return _Drones;
}
ControlCenter::~ControlCenter() {

}



