enum State { FORWARD, BACKWARD, STOP, EXECUTE };
State state = FORWARD;
int targetTicks = 65; 
int parkingStartPos = 0; 

float kp_back = 2.0;
float ki_back = 0.0;
float kd_back = 0.5;

int e_back = 0;
int eprev_back = 0;
float eintegral_back = 0;

void readEncoder() {
  int b = -digitalRead(ENCB);
  if (b > 0) {
    posi++;
  }
  else {
    posi--;
  }
}

void encoder() {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    pos = posi;
  }
}

void executeParking() {
  encoder();
  if (laser_left < laser_right) {
    stayLeft  = true; 
    if (laser_center > 5 && state == FORWARD) {
      state = FORWARD;
      motorSpeed = 120;
      servoRotate.write(servoRight - 3);
      moveForward();
    }
    else if (laser_center <= 5 && state == FORWARD) {
      stopMotors();
      delay(300);
      parkingStartPos = pos;
      state = BACKWARD;


      e_back = 0;
      eprev_back = 0;
      eintegral_back = 0;
    }
    else if (state == BACKWARD) {
      motorSpeed = 150;
      servoRotate.write(servoLeft + 9);
      int ticksMoved = parkingStartPos - pos;
      int target = targetTicks;

      if (ticksMoved < target) {
        e_back = target - ticksMoved;
        float dedt = e_back - eprev_back;
        eintegral_back += e_back;

        float u = kp_back * e_back + kd_back * dedt + ki_back * eintegral_back;

        motorSpeed = constrain(abs(u), 50, 150);

        eprev_back = e_back;

        moveBackward();
      } else {
        stopMotors();
        state = EXECUTE;
      }
    }
    else if (state == EXECUTE) {
      servoRotate.write(servoRight - 3);
      motorSpeed = 130;
      moveForward();
      delay(500);
      state = STOP;
    }
    else if (state == STOP) {
      stopMotors();
      executed = true;
    }
  }



  else {
    stayLeft  = false; 
    if (laser_center > 5 && state == FORWARD) {
      state = FORWARD;
      motorSpeed = 140;
      servoRotate.write(servoLeft + 6);
      moveForward();
    }
    else if (laser_center <= 5 && state == FORWARD) {
      stopMotors();
      delay(300);
      parkingStartPos = pos;
      state = BACKWARD;

      e_back = 0;
      eprev_back = 0;
      eintegral_back = 0;
    }
    else if (state == BACKWARD) {
      motorSpeed = 190;
      servoRotate.write(servoRight - 7);
      int ticksMoved = parkingStartPos - pos;
      int target = targetTicks;

      if (ticksMoved < target) {
        e_back = target - ticksMoved;
        float dedt = e_back - eprev_back;
        eintegral_back += e_back;

        float u = kp_back * e_back + kd_back * dedt + ki_back * eintegral_back;

        motorSpeed = constrain(abs(u), 80, 150);

        eprev_back = e_back;

        moveBackward();
      } else {
        stopMotors();
        state = EXECUTE;
      }
    }
    else if (state == EXECUTE) {
      servoRotate.write(servoLeft + 6);
      motorSpeed = 130;
      moveForward();
      delay(500);
      state = STOP;
    }
    else if (state == STOP) {
      stopMotors();
      delay(500); 
      
      servoAngle = servoNeutral;
      servoRotate.write(servoNeutral);
      motorSpeed = 120;

      error = 0;
      previousError = 0;
      integral = 0;
      derivative = 0;

      executed = true;
    }
  }

}
