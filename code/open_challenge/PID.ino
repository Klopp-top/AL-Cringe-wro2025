void pid() {
  error = laser_right - laser_left;

  if (abs(error) < 5) {
    error = 0;
  }

  integral += error;
  derivative = error - previousError;
  float output = (Kp * error) + (Ki * integral) + (Kd * derivative);
  previousError = error;

//  servoAngle = servoNeutral + output / 2;
  servoAngle = map (output, 1100, -1100, servoRight, servoLeft);
  servoAngle = constrain(servoAngle, servoRight, servoLeft);

  if (laser_center < 4) {
    motorSpeed = 0;
  }

  servoRotate.write(servoAngle);

//  Serial.print("Error: ");
//  Serial.println(output);
//  Serial.print(" | Servo: ");
//  Serial.println(servoAngle);
}
