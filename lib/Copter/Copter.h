#ifndef COPTER_H
#define COPTER_H

class Copter
{
private:
    /* data */
public:
    Copter(/* args */){}
    ~Copter(){}

    void setup();
    void loop_task();
    
};

extern Copter copter;


#endif