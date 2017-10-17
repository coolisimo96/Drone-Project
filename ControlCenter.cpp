//
// Created by cjlon on 10/2/2017.
//
#include <iostream>
#include "ControlCenter.h"
#include <chrono>
using namespace std;

/*
 * Constructor for the Control Center, which contains the map of the area, as well as a list of available payload drop offs and hover spots
 *
 * @param x = number of cols in map
 * @param y = number of rows in map
 */
ControlCenter::ControlCenter(int x, int y) {
    _x=x;
    _y=y;
    for(int i=0;i<_x;i++){
        _map.emplace_back(vector<Coordinate>());
        for(int j=0;j<_y;j++){
            _map[i].emplace_back(Coordinate(i,j));
            //cout<<_map[i][j][k].getX()<<","<<_map[i][j][k].getY()<<","<<_map[i][j][k].getZ()<<endl;
            }
        }
    generateTaskList(_x,_y);
    generateHoverList(_x,_y);
}
vector<Coordinate> ControlCenter::getHoverList(){
    return _hoverList;
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
                _taskList.emplace_back( _map[i][j]);
                //cout <<"TaskSpot: "<< _taskList[flag].getX() << ","<<_taskList[flag].gety()<<std::endl;
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
                _hoverList.emplace_back(_map[i][j]);
                //cout <<"HoverSpot: "<< _hoverList[flag].getX() << ","<<_hoverList[flag].gety()<<std::endl;
                ++flag;
            }
        }
    }
}
void ControlCenter::registerDrones(vector<Drone>& drones) {
    _drones=drones;
    cout<<_drones[0].getLocation().getX()<<endl;
}

vector<Drone> ControlCenter::getDrones() {
    return _drones;
}
Coordinate ControlCenter::getLocation(int x, int y){
    return _map[x][y];
}
void ControlCenter::printMap(){
    while(true) {
        for (int i = 0; i <= _x * 3; i++) {
            for (int j = 0; j < _y; j++) {
                if (i % 3 == 0) {
                    cout << "|--------";
                }
                else if ((i == (_x * 3) / 2) && (j == _y / 2)) {
                    cout << "|  DCAC  ";
                }
                else if(((i/4)==_drones[0].getLocation().getX())&&(j==_drones[0].getLocation().getY())){
                    cout<<"|  D0"<<"    ";
                }
                else {
                    cout << "|        ";
                }
                if (j == (_y - 1)) {
                    cout << "|" << endl;
                }
            }
        }
        cout<<endl<<endl<<endl;
        Sleep(10000);
    }
}
/*
 * Deconstructor for the control center
 */
ControlCenter::~ControlCenter() {

}



