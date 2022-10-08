#ifndef GPS_H
#define GPS_H

#define DEG2RAD 0.01745329252

class GPS
{
private:
    float x, y, z;

public:
    GPS() {}
    ~GPS() {}

    void toCartesian(float latitude, float longitude);
};

extern GPS gps;

#endif