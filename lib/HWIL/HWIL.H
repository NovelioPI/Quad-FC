#ifndef HWIL_H
#define HWIL_H

#include <Arduino.h>
#include <nanopb/pb_encode.h>
#include <nanopb/pb_decode.h>

#define HEAD '&'

class HWILCommunication
{
private:
    float gyroX;
    float gyroY;
    float gyroZ;
    float accX;
    float accY;
    float accZ;
    float relativeAlt;
    float lat;
    float lon;


public:
    uint8_t pwm[4];

    HWILCommunication(/* args */){}
    ~HWILCommunication(){}

    void HWILThread();

    void sendMessage();
    void receiveMessage();

    float getGyroX() { return gyroX; }
    float getGyroY() { return gyroY; }
    float getGyroZ() { return gyroZ; }
    float getAccX() { return accX; }
    float getAccY() { return accY; }
    float getAccZ() { return accZ; }
    float getRelativeAlt() { return relativeAlt; }
    float getLat() { return lat; }
    float getLon() { return lon; }
};

extern HWILCommunication hwil;

#endif