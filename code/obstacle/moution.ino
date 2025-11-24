void moveForward() {
  analogWrite(MOTOR_PWM, motorSpeed);
  
  digitalWrite(MOTOR_DIR_FRONT, 1);
  digitalWrite(MOTOR_DIR_BACK, 0);
  
}

void moveBackward() {
  analogWrite(MOTOR_PWM, motorSpeed);
  
  digitalWrite(MOTOR_DIR_FRONT, 0);
  digitalWrite(MOTOR_DIR_BACK, 1);
}

void stopMotors () {
  analogWrite(MOTOR_PWM, 0);
} 
