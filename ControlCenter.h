//
// Created by cjlon on 10/2/2017.
//

#ifndef CSE321_PROJECT_1_CONTROLCENTER_H
#define CSE321_PROJECT_1_CONTROLCENTER_H

#endif //CSE321_PROJECT_1_CONTROLCENTER_H
class ControlCenter{
private:
    int _map[0][0][4];
public:
    ControlCenter();

    ControlCenter(int x,int y);

    ~ControlCenter();

    void assignTask();

    void registerDrone();
};