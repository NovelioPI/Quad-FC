#include <HWIL.H>
#include "hwil.pb.h"
#include <Copter.h>

void chStart()
{
  hwil.HWILThread();
}

void setup() {
  Serial.begin(115200);
  Serial.clear();

  copter.setup();
}

void loop() {
  copter.loopTask();
}

void HWILCommunication::sendMessage()
{
  // Serial.println("send");
	uint8_t buffer[100];
  HWIL msg = HWIL_init_zero;

  pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

	msg.pwm[0] = pwm[0];
  msg.pwm[1] = pwm[1];
  msg.pwm[2] = pwm[2];
  msg.pwm[3] = pwm[3];
  msg.pwm_count = 4;
  
  pb_encode(&stream, HWIL_fields, &msg);
  size_t message_length = stream.bytes_written;

  Serial.write(buffer, message_length);
  Serial.println();
  Serial.flush();
}

void HWILCommunication::receiveMessage()
{
  // Serial.println("receive");
	if(Serial.available()){
    int length = Serial.read();
    delay(10);

    uint8_t buffer[length];

    for(int i=0; i<length; i++)
      buffer[i] = Serial.read();
    
    HWIL msg = HWIL_init_zero;

    pb_istream_t stream = pb_istream_from_buffer(buffer, length);
    pb_decode(&stream, HWIL_fields, &msg);

    gyroX = msg.gyroX;
    gyroY = msg.gyroY;
    gyroZ = msg.gyroZ;
    accX = msg.accX;
    accY = msg.accY;
    accZ = msg.accZ;
    relativeAlt = msg.relativeAlt;
    lat = msg.latitude;
    lon = msg.longitude;
	}    
}