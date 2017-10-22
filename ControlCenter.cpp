//
// Created by cjlon on 10/2/2017.
//
#include <iostream>
#include <thread>
#include <chrono>
#include "ControlCenter.h"
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
Coordinate& ControlCenter::assignTask() {
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
                //_map[i][j].addCount();
                _taskList.emplace_back( _map[i][j]);
                _map[i][j].setCategory(1);
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
    for(int i=0;i<_drones.size();i++){
        _map[_drones[i].getLocation().getX()][_drones[i].getLocation().getY()].occupySpace();
    }
}

void ControlCenter::printMap(){
    while(1) {
        for (int i = 0; i <= _x * 3; i++) {
            for (int j = 0; j < _y; j++) {
                if (i % 3 == 0) {
                    cout << "|--------";
                } else if ((i == (_x * 3) / 2) && (j == _y / 2)) {
                    cout << "|  DCAC  ";
                } else if ((isDroneSpot(i, j)) && (i % 3 == 1)) {
                    //should probably fix this later
                } else if ((_map[i / 3][j].getCategory() == 1) && (i % 3 == 2)) {
                    cout << "|   " << _map[i / 3][j].getCount() << "    ";
                } else {
                    cout << "|        ";
                }
                if (j == (_y - 1)) {
                    cout << "|" << endl;
                }
            }
        }
        cout << endl << endl << endl;
        std::this_thread::sleep_for(chrono::milliseconds(1200));
    }
}
bool ControlCenter::isDroneSpot(int i,int j){
    for(int k=0;k<_drones.size();k++){
        if((_map[i/3][j].getX()==_drones[k].getLocation().getX())&&(_map[i/3][j].getY()==_drones[k].getLocation().getY())){
            if(i%3==1){
                if(k<10) {
                    cout << "|   D" << k << "   ";
                }
                else{
                    cout << "|  D" << k << "   ";
                }
            }
            return true;
        }
    }
    return false;
}

void ControlCenter::moveDrones(int index){
    while(true){
        //cout<<index<<endl;
        if(!_drones[index].hasPayload()){
            if(_drones[index].isGettingPayload()){
                if(_drones[index].getLocation().getX()<_x/2) {
                    moveDronesHelper(index, 0);
                }
                else if(_drones[index].getLocation().getX()> _x/2){
                    moveDronesHelper(index,1);
                }
                else{
                    if(_drones[index].getLocation().getY()>_x/2) {
                        moveDronesHelper(index, 2);
                    }
                    else if(_drones[index].getLocation().getY()<_x/2) {
                        moveDronesHelper(index, 3);
                    }
                    else{
                        _drones[index].gettingPayload(false);
                        _drones[index].loadDrone(true);
                        if(index!=_drones.size()-1) {
                            _drones[index+1].gettingPayload(true);
                            _drones[index+1].loadDrone(false);
                        }
                        else{_drones[0].gettingPayload(true);}
                        //cout<<"Got Payload"<<endl;
                    }
                }
            }
            else{
                std::this_thread::sleep_for(chrono::milliseconds(1000));
                moveDrones(index);
            }
        }
        else{
            if(_drones[index].getLocation().getX()<_drones[index].getDestination().getX()) {
                moveDronesHelper(index, 0);
            }
            else if(_drones[index].getLocation().getX()>_drones[index].getDestination().getX()){
                moveDronesHelper(index,1);
            }
            else{
                if(_drones[index].getLocation().getY()>_drones[index].getDestination().getY()) {
                    moveDronesHelper(index, 2);
                }
                else if(_drones[index].getLocation().getY()<_drones[index].getDestination().getY()) {
                    moveDronesHelper(index, 3);
                }
                else{
                    _map[_drones[index].getLocation().getX()][_drones[index].getLocation().getY()].addCount();
                    _drones[index].loadDrone(false);
                    _drones[index].gettingPayload(true);
                    _drones[index].setDestination(_taskList[rand()%_hoverList.size()]);
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
/*
 * Helper so code doesn't need to be reused, moves drones based on the direction specified
 * 0=Right
 * 1=Left
 * 2=Up
 * 3=Down
 */
void ControlCenter::moveDronesHelper(int index, int direction){
        switch (direction) {
            case 0:
                if(_drones[index].getLocation().getX()!=_x-1) {
                    if (_map[_drones[index].getLocation().getX() +
                             1][_drones[index].getLocation().getY()].occupySpace()) {
                        _map[_drones[index].getLocation().getX()][_drones[index].getLocation().getY()].unlockLoc();
                        _drones[index].setLoctation(
                                _map[_drones[index].getLocation().getX() + 1][_drones[index].getLocation().getY()]);
                        //cout<<"("<<_drones[index].getLocation().getX()<<","<<_drones[index].getLocation().getY()<<")";
                        break;
                    }
                }
            case 1:
                if(_drones[index].getLocation().getX()!=0) {
                    if (_map[_drones[index].getLocation().getX() -
                             1][_drones[index].getLocation().getY()].occupySpace() &&
                        (_drones[index].getLocation().getX() < _x - 1)) {
                        _map[_drones[index].getLocation().getX()][_drones[index].getLocation().getY()].unlockLoc();
                        _drones[index].setLoctation(
                                _map[_drones[index].getLocation().getX() - 1][_drones[index].getLocation().getY()]);
                        //cout<<"("<<_drones[index].getLocation().getX()<<","<<_drones[index].getLocation().getY()<<")";
                        break;
                    }
                }
            case 2:
                if(_drones[index].getLocation().getY()!=0) {
                    if (_map[_drones[index].getLocation().getX()][_drones[index].getLocation().getY() -
                                                                  1].occupySpace()) {
                        _map[_drones[index].getLocation().getX()][_drones[index].getLocation().getY()].unlockLoc();
                        _drones[index].setLoctation(
                                _map[_drones[index].getLocation().getX()][_drones[index].getLocation().getY() - 1]);
                        //cout<<"("<<_drones[index].getLocation().getX()<<","<<_drones[index].getLocation().getY()<<")";
                        break;
                    }
                }
            case 3:
                if(_drones[index].getLocation().getY()!=_y-1) {
                    if (_map[_drones[index].getLocation().getX()][_drones[index].getLocation().getY() +
                                                                  1].occupySpace()) {
                        _map[_drones[index].getLocation().getX()][_drones[index].getLocation().getY()].unlockLoc();
                        _drones[index].setLoctation(
                                _map[_drones[index].getLocation().getX()][_drones[index].getLocation().getY() + 1]);
                        //cout<<"("<<_drones[index].getLocation().getX()<<","<<_drones[index].getLocation().getY()<<")";
                        break;
                    }
                }
        }
    }
/*
 * Deconstructor for the control center
 */
ControlCenter::~ControlCenter() {

}



