#include "HWIL.H"

void HWIL::decode(String data)
{
    int p = 0;
    int i = data.indexOf(",");
    gyro_x = data.substring(p,i).toFloat();

    p = i + 1;
    i = data.indexOf(",",p);
    gyro_y = data.substring(p,i).toFloat();

    p = i + 1;
    i = data.indexOf(",",p);
    gyro_z = data.substring(p,i).toFloat();

    p = i + 1;
    i = data.indexOf(",",p);
    acc_x = data.substring(p,i).toFloat();

    p = i + 1;
    i = data.indexOf(",",p);
    acc_y = data.substring(p,i).toFloat();

    p = i + 1;
    i = data.indexOf(",",p);
    acc_z = data.substring(p,i).toFloat();

    p = i + 1;
    i = data.indexOf(",",p);
    alt_sonar = data.substring(p,i).toFloat();

    p = i + 1;
    i = data.indexOf(",",p);
    lat = data.substring(p,i).toFloat();

    p = i + 1;
    i = data.indexOf(",",p);
    lon = data.substring(p,i).toFloat();

    p = i + 1;
    i = data.indexOf(",",p);
    alt = data.substring(p,i).toFloat();
}

HWIL hwil;