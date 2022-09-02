#ifndef HWIL_H
#define HWIL_H

#include <Arduino.h>

class HWIL
{
private:
    float gyro_x;
    float gyro_y;
    float gyro_z;
    float acc_x;
    float acc_y;
    float acc_z;
    float alt_sonar;
    float lat;
    float lon;
    float alt;

public:
    HWIL(/* args */){}
    ~HWIL(){}

    void decode(String data);

    float get_gyro_x() { return gyro_x; }
    float get_gyro_y() { return gyro_y; }
    float get_gyro_z() { return gyro_z; }
    float get_acc_x() { return acc_x; }
    float get_acc_y() { return acc_y; }
    float get_acc_z() { return acc_z; }
    float get_alt_sonar() { return alt_sonar; }
    float get_lat() { return lat; }
    float get_lon() { return lon; }
    float get_alt() { return alt; }
};

extern HWIL hwil;

#endif