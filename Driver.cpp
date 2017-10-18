#include "controlCenter.h"
#include <iostream>
using namespace std;
int main() {
    ControlCenter DCAS(7,7);
    vector<Drone> drones;
    vector<thread> droneThreads;
    for(int i=0;i<10;i++) {
        drones.emplace_back();
        droneThreads.emplace_back();
    }

    for(int i=0;i<10;i++){
        drones[i].setLoctation(DCAS.getHoverList()[i]);
        drones[i].setDestination(DCAS.assignTask());

        DCAS.registerDrones(drones);
        DCAS.getDrones()[i].getLocation().occupySpace();
        cout<<DCAS.getDrones()[i].getLocation().getOcc()<<endl;
    }

    thread map(&ControlCenter::printMap,DCAS);
    for(int i=0;i<10;i++){
        droneThreads[i].join();
    }
    map.join();
    return 0;
}