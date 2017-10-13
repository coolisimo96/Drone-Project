//
// Created by cjlon on 10/2/2017.
//
#include <iostream>
#include "ControlCenter.h"
using namespace std;

/*
 * Constructor for the Control Center, which contains the map of the area, as well as a list of available payload drop offs and hover spots
 *
 * @param x = number of cols in map
 * @param y = number of rows in map
 */
ControlCenter::ControlCenter(int x, int y) {

    for(int i=0;i<x;i++){
        _map.emplace_back(vector<vector<Coordinate>>());
        for(int j=0;j<y;j++){
            _map[i].emplace_back(vector<Coordinate>());
            for(int k=0;k<4;k++){
                _map[i][j].emplace_back(Coordinate(i,j,k));
                _map[i][j][k].setCategory(1);
                cout<<_map[i][j][k].getX()<<","<<_map[i][j][k].gety()<<","<<_map[i][j][k].getz()<<endl;
            }
        }
    }
    generateTaskList(x,y);
    generateHoverList(x,y);
    _map[x/2][y/2][0].setCategory(0);

}
/*
 * Returns _tasklist, a vector containing the possible locations for a drone to drop off a payload
 */
vector<Coordinate> ControlCenter::getTaskList() {
    return _taskList;
}
/*
 * Returns a rancomly selected coordinate from the list of available drop off locations for a drone to attempt to reach
 */
Coordinate ControlCenter::assignTask() {
    int randNum = rand() % _taskList.size();
    return _taskList[randNum];
}
/*
 * Generates a vector containing coordinates which are determined as available for a drone to drop off a payload
 */
void ControlCenter::generateTaskList(int x, int y) {
    int flag=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(i==0 || i==x-1 || j==0 || j==y-1){
                _taskList.emplace_back( _map[i][j][0]);
                _taskList[flag].setCategory(1);
                cout <<"TaskSpot: "<< _taskList[flag].getX() << ","<<_taskList[flag].gety()<<std::endl;
                ++flag;
            }
        }
    }
}
/*
 * Generates a vector containing coordinates which are determined as available for a drone to hover as it waits for its
 * turn to retrieve a payload
 */
void ControlCenter::generateHoverList(int x, int y) {
    int flag=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(((i==1||i==x-2)&&(j>0&&j<x-1))||((j==1||j==y-2)&&(i>0&&i<y-1))){
                _hoverList.emplace_back(_map[i][j][1]);
                _taskList[flag].setCategory(2);
                cout <<"HoverSpot: "<< _hoverList[flag].getX() << ","<<_hoverList[flag].gety()<<std::endl;
                ++flag;
            }
        }
    }
}
/*
 * registers a drone to the control center, may not be implemented
 */
void ControlCenter::registerDrone(Drone newDrone) {
    _Drones.push_back(newDrone);
}
/*
 * Returns a list of drones registered to the control center, may not be implemented
 */
vector<Drone> ControlCenter::getDrones(){
    return _Drones;
}
/*
 * Deconstructor for the control center
 */
ControlCenter::~ControlCenter() {

}



