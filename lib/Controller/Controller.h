#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <BasicLinearAlgebra.h>

class Controller
{
private:
    void set_state();
    BLA::Matrix<3, 1> rotateGFtoBF(float X, float Y, float Z, float phi, float theta, float psi);

    BLA::Matrix<12, 1> state;
    BLA::Matrix<12, 1> state_ref;
    BLA::Matrix<12, 1> state_error;

    BLA::Matrix<4, 12> K;
    BLA::Matrix<4, 1> u;

    float Kd = 0;   // Drag torque proportional constant
    float KT = 0;   // thrust coefficient
    float l = 0;    // Length of arm


public:
    Controller(/* args */){};
    ~Controller(){};

    void main_control();
};

extern Controller ctl;

#endif