#include "Copter.h"
#include <TaskScheduler.h>
#include <HWIL.H>

#define _TASK_MICRO_RES
#define _TASK_PRIORITY
#define _TASK_THREAD_SAFE
#define _TASK_TIMEOUT

void receive();
void updateAHRS();
void controlSystem();
void send();

Scheduler sch;

Task rx(10, TASK_FOREVER, &receive, &sch, true);
Task ahrs (1, TASK_FOREVER, &updateAHRS, &sch, true);
Task control(10, TASK_FOREVER, &controlSystem, &sch, true);
Task tx(10, TASK_FOREVER, &send, &sch, true);
// Task t2(500, TASK_FOREVER, &controlOption, &runner, true);
// Task t3(20000, TASK_FOREVER, &getDesState, &runner, true);
// Task t4(2500, TASK_FOREVER, &controlMixer, &runner, true);
// Task t5(2500, TASK_FOREVER, &scaleCommands, &runner, true);
// Task t6(2500, TASK_FOREVER, &commandMotors, &runner, true);

void Copter::setup()
{
    // sch.enableAll();
    // sch.startNow();
}

void Copter::loopTask()
{
    sch.execute();
}

void receive()
{
    hwil.receiveMessage();
}

void updateAHRS()
{
    imu.updateAHRS();
}

void controlSystem()
{
    ctl.main_control();
}

void send()
{
    hwil.sendMessage();
}

Copter copter;