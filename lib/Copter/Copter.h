#ifndef COPTER_H
#define COPTER_H

#include <IMU/IMU.h>
#include <Controller.h>

class Copter
{
private:
    /* data */
public:
    Copter(/* args */){}
    ~Copter(){}

    void setup();
    void loopTask();
    
};

extern Copter copter;


#endif