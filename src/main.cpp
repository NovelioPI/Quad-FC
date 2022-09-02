#include <HWIL.H>
// #include <Controller.h>

void setup() {
  Serial.begin(115200);
  Serial.clear();
}

void loop() {
  // ctl.main_control();
  if(Serial.available()){
    String data = Serial.readStringUntil('\n');

    hwil.decode(data);
    
    Serial.print("gyro_x:");
    Serial.println(hwil.get_gyro_x(), 8);
  }
}