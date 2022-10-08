#include "IMU.h"
#include "MadgwickAHRS.h"
#include <HWIL.H>

void IMU::updateAHRS()
{
    MadgwickAHRSupdateIMU(dt,
                          hwil.getGyroX(),
                          hwil.getGyroY(),
                          hwil.getGyroZ(),
                          hwil.getAccX(),
                          hwil.getAccY(),
                          hwil.getAccZ());

    //compute angles
    roll = atan2(q0*q1 + q2*q3, 0.5f - q1*q1 - q2*q2)*57.29577951; //degrees
    pitch = -asin(-2.0f * (q1*q3 - q0*q2))*57.29577951; //degrees
    yaw = -atan2(q1*q2 + q0*q3, 0.5f - q2*q2 - q3*q3)*57.29577951; //degrees
}

IMU imu;