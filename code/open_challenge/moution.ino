void moveForward() {
  analogWrite(MOTOR_PWM, motorSpeed);
  
  digitalWrite(MOTOR_DIR_FRONT, 1);
  digitalWrite(MOTOR_DIR_BACK, 0);
  
}

void stopMotors () {
  analogWrite(MOTOR_PWM, 0);
} 

void sharpTurn() {

  pos = 0;
  
  if (pos < target_ticks) {
    servoRotate.write(50);
    analogWrite(4, 150); // Включение мотора
    digitalWrite(6, 0);
    digitalWrite(5, 1);
  } else if (pos > target_ticks) {
    servoRotate.write(70);
    analogWrite(4, 0); // Остановка мотора
  }
}
