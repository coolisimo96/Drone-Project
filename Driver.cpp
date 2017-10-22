#include "ControlCenter.h"
#include <thread>
#include <iostream>
using namespace std;
int main(int argc, char**argv) {
    int droneNum=10,y=0,x=0;
    cout<<"Enter the amount of drones desired: "<<endl;
    cin>>droneNum;
    while(x<3){
        cout<<"Please enter a value greater than 4 for disired legnth: "<<endl;
        cin>>x;
    }
    while(y<3){
        cout<<"Please enter a value greater than 4 for disired height: "<<endl;
        cin>>y;
    }
    ControlCenter* DCAS= new ControlCenter(x,y);
    vector<Drone> drones;
    vector<thread> droneThreads;

    for(int i=0;i<droneNum;i++){
        drones.emplace_back();
        drones[i].setLoctation(DCAS->getHoverList()[i]);
        drones[i].setDestination(DCAS->assignTask());
        drones[i].getLocation().occupySpace();
    }
    DCAS->registerDrones(drones);
    droneThreads.push_back(thread(&ControlCenter::printMap,DCAS));

    for(int i=0;i<droneNum;i++){
        droneThreads.push_back(thread(DCAS->moveDrones,DCAS,i));
    }

    for(int i=0;i<droneNum;i++){
        droneThreads[i].join();
    }

    return 0;
}