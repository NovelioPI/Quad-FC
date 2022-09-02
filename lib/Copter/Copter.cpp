#include "Copter.h"
#include <TaskScheduler.h>

#define _TASK_MICRO_RES
#define _TASK_PRIORITY
#define _TASK_THREAD_SAFE
#define _TASK_TIMEOUT

Scheduler sch;

Task t1(500, TASK_FOREVER, &updateAHRS, &runner, true);
Task t2(500, TASK_FOREVER, &controlOption, &runner, true);
Task t3(20000, TASK_FOREVER, &getDesState, &runner, true);
Task t4(2500, TASK_FOREVER, &controlMixer, &runner, true);
Task t5(2500, TASK_FOREVER, &scaleCommands, &runner, true);
Task t6(2500, TASK_FOREVER, &commandMotors, &runner, true);

void Copter::setup()
{
    sch.enableAll();
    sch.startNow();
}

void Copter::loop_task()
{
    sch.execute();
}