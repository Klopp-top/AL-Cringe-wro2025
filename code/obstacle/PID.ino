void pid() {
  error = laser_right - laser_left;

  if (abs(error) < 2) {
    error = 0;
  }

  if (laser_center < 60) {
    if (left_laser > right_laser && left_laser > 30) {
      motorSpeed = 130;
      servoAngle = servoLeft + 5;
    } else if (left_laser < right_laser && right_laser > 30) {
      motorSpeed = 130;
      servoAngle = servoRight - 5;
    }
    return;
  }
  integral += error;
  derivative = error - previousError;
  float output = (Kp * error) + (Ki * integral) + (Kd * derivative);
  previousError = error;

  servoAngle = map(output, 900, -900, servoRight - 3, servoLeft + 3);
  servoAngle = constrain(servoAngle, servoRight, servoLeft);

  if (laser_left < 22) {
    servoAngle = servoRight - 3;
    return;
  } else if (laser_right < 22) {
    servoAngle = servoLeft + 3;
    return;
  }

  if (left_laser < 8) {
    servoAngle = servoRight - 3;
    return;
  } else if (right_laser < 8) {
    servoAngle = servoLeft + 3;
    return;
  }
}
