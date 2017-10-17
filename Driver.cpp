#include "controlCenter.h"
#include <iostream>
using namespace std;
int main() {
    ControlCenter DCAS(7,7);
    vector<Drone> drones;
    Drone test;
    for(int i=0;i<10;i++) {
        drones.emplace_back(test);
    }
    for(int i=0;i<10;i++){
        drones[i].setLoctation(DCAS.getHoverList()[i]);
        drones[i].getLocation().occupySpace();
        drones[i].setDestination(DCAS.assignTask());
        cout<<"Destination for Drone "<<i<<": "<<drones[i].getLocation().getX() << ", "<< drones[i].getLocation().getY()<<endl;

    }
    DCAS.registerDrones(drones);
    //drones[0].setLoctation(DCAS.getLocation(1,1));
    cout<<drones[0].getLocation().getX()<<","<<drones[0].getLocation().getY()<<endl;
    cout<<DCAS.getDrones()[0].getLocation().getX()<<","<<DCAS.getDrones()[0].getLocation().getY()<<endl;
    //cout<<drones[1].getLocation().getX()<<","<<drones[1].getLocation().getY()<<endl;

    //thread map(&ControlCenter::printMap,DCAS);
    //map.join();
    return 0;
}