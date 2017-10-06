//
// Created by cjlon on 10/2/2017.
//
#include "ControlCenter.h"

ControlCenter::ControlCenter(int x, int y) {
    Coordinate _map[x][y][4];
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(int k=0;k<4;k++){
                _map[i][j][k]=new Coordinate(i,j,k);
            }
        }
    }
    Coordinate unloadPoints[x+y+(x-2)+(y-2)];
    unloadPoints=generateTaskList(_map);

}
Coordinate* ControlCenter::generateTaskList(int x, int y) {
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(i==0 || i==x-1){

            }
        }
    }
}
void ControlCenter::assignTask() {

}

void ControlCenter::registerDrone() {

}

ControlCenter::~ControlCenter() {

}



