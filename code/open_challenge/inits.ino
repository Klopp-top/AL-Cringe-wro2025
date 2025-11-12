void initRobot() {
  initMotors();
  initButton();
  //initColorSensor();
  initServo();
  initEncoder();
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

  digitalWrite(XSHUT1, LOW);
  digitalWrite(XSHUT2, LOW);
  digitalWrite(XSHUT3, LOW);
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

  sensor_left.startContinuous();
  sensor_center.startContinuous();
  sensor_right.startContinuous();
}

void initEncoder() {
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
}
