void initRobot() {
  initEncoder();
  initMotors();
  initButton();
  //initColorSensor();
  initServo();
  initCam();
  initLaser();
  servoRotate.write(servoNeutral);
}

void initMotors() {
  pinMode(MOTOR_DIR_BACK, OUTPUT);
  pinMode(MOTOR_DIR_FRONT, OUTPUT);
}

void initButton() {
  pinMode(KNOPKA, INPUT);
}

void initServo() {
  servoRotate.attach(SERVO_ROTATE);
  servoCam.attach(SERVO_CAM);

}

//void initColorSensor() {
//  pinMode(S0, OUTPUT);
//  pinMode(S1, OUTPUT);
//  pinMode(S2, OUTPUT);
//  pinMode(S3, OUTPUT);
//
//  pinMode(sensorOut, INPUT);
//}

void initCam() {
  pixy.init();
}

void initLaser() {
  
  pinMode(XSHUT1, OUTPUT);
  pinMode(XSHUT2, OUTPUT);
  pinMode(XSHUT3, OUTPUT);
  pinMode(XSHUT4, OUTPUT);
  pinMode(XSHUT5, OUTPUT);

  digitalWrite(XSHUT1, LOW);
  digitalWrite(XSHUT2, LOW);
  digitalWrite(XSHUT3, LOW);
  digitalWrite(XSHUT4, LOW);
  digitalWrite(XSHUT5, LOW);
  delay(10);

  digitalWrite(XSHUT1, HIGH);
  delay(10);
  sensor_left.init();
  sensor_left.setAddress(0x30);
  sensor_left.setTimeout(50);

  digitalWrite(XSHUT2, HIGH);
  delay(10);
  sensor_center.init();
  sensor_center.setAddress(0x31);
  sensor_center.setTimeout(50);

  digitalWrite(XSHUT3, HIGH);
  delay(10);
  sensor_right.init();
  sensor_right.setAddress(0x32);
  sensor_right.setTimeout(50);

  digitalWrite(XSHUT4, HIGH);
  delay(10);
  left_sensor.init();
  left_sensor.setAddress(0x33);
  left_sensor.setTimeout(50);

  digitalWrite(XSHUT5, HIGH);
  delay(10);
  right_sensor.init();
  right_sensor.setAddress(0x34);
  right_sensor.setTimeout(50);

  sensor_left.startContinuous();
  sensor_center.startContinuous();
  sensor_right.startContinuous();
  left_sensor.startContinuous();
  right_sensor.startContinuous();
}

void initEncoder() {
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
}
