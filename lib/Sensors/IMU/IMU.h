#ifndef IMU_H
#define IMU_H

class IMU
{
private:
    float dt = 0.01;
    float roll, pitch, yaw;

public:
    IMU(/* args */){}
    ~IMU(){}

    void updateAHRS();

    float get_roll() { return roll; }
    float get_pitch() { return pitch; }
    float get_yaw() { return yaw; }
};

extern IMU imu;

#endif