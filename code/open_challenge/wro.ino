#include <Servo.h>
#include <Pixy2.h>
#include <Wire.h>
#include <NewPing.h>
#include <VL53L0X.h>
#include <util/atomic.h>
#include "config.h"

Pixy2 pixy;

VL53L0X sensor_left;
VL53L0X sensor_center;
VL53L0X sensor_right;

Servo servoRotate, servoCam;

NewPing left(TRIGGER_LEFT, ECHO_LEFT, MAX_DISTANCE);
NewPing right(TRIGGER_RIGHT, ECHO_RIGHT, MAX_DISTANCE);

void setup() {
  Wire.begin();
  Serial.begin(115200);
  initRobot();
  ayat();
}

void loop() {
  if (digitalRead(KNOPKA) == 1 && !start) {
    getLaserDistance();
    start = true;
  } else if (start) {
    getDataFromCam();
    pid();
    getLaserDistance();
    moveForward();

  }
}
