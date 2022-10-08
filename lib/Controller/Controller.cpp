#include "Controller.h"
#include <IMU/IMU.h>
#include <HWIL.H>

void Controller::main_control()
{
    set_state();

    state_error = state_ref - state;

    u = -K*state_error;

    // TO DO limiting control inputs (u), ex:
    // u(0) = constrain(u(0), u0_min, u0_max);

    float omega[4];

    omega[0] = sqrt(u(0)/(4*KT) + u(2)/(2*l*KT) + u(3)/(4*Kd));
    omega[1] = sqrt(u(0)/(4*KT) - u(1)/(2*l*KT) - u(3)/(4*Kd));
    omega[2] = sqrt(u(0)/(4*KT) - u(2)/(2*l*KT) + u(3)/(4*Kd));
    omega[3] = sqrt(u(0)/(4*KT) + u(1)/(2*l*KT) - u(3)/(4*Kd));

    hwil.pwm[0] = omega[0];
    hwil.pwm[1] = omega[1];
    hwil.pwm[2] = omega[2];
    hwil.pwm[3] = omega[3];
}

void Controller::set_state()
{
    auto BF = rotateGFtoBF(0, 0, 1, imu.get_roll(), imu.get_pitch(), imu.get_yaw());

    state = {BF(0), BF(1), BF(2), 
             0, 0, 0,
             imu.get_roll(), imu.get_pitch(), imu.get_yaw(),
             hwil.getGyroX(), hwil.getGyroY(), hwil.getGyroZ()};
    
    state_ref = {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
}

BLA::Matrix<3, 1> Controller::rotateGFtoBF(float X, float Y, float Z, float phi, float theta, float psi)
{
    BLA::Matrix<3, 3> R_roll, R_pitch, R_yaw;

    R_roll = {
        1, 0, 0,
        0, cosf(phi), -sinf(phi),
        0, sinf(phi), cosf(phi)
    };

    R_pitch = {
        cosf(theta), 0, sinf(theta),
        0, 1, 0,
        sinf(theta), 0, cosf(theta)
    };

    R_yaw = {
        cosf(psi), -sinf(psi), 0,
        sinf(psi), cosf(psi), 0,
        0, 0, 1
    };

    auto R = R_roll* R_pitch * R_yaw;

    BLA::Matrix<3, 1> XF = {X, Y, Z};
    auto XG = R*XF;

    return XG;
}

Controller ctl;