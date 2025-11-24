unsigned long lastCountTime = 0;

void getDataFromCam() {
  int i;
  pixy.ccc.getBlocks();

  if (turnCount < 3) {
    if (pixy.ccc.numBlocks) {

      for (i = 0; i < pixy.ccc.numBlocks; i++) {
        Serial.print("  блок ");
        Serial.print(i);
        Serial.print(": ");
        pixy.ccc.blocks[i].print();

        if (pixy.ccc.blocks[i].m_signature == 3) {
          pid();
          Serial.print("Общее количество сигнатур 3: ");
          Serial.println(turnCount);
          if (millis() - lastCountTime >= 5000) {
            lastCountTime = millis();
            turnCount++;
          }
        }
      }
    }
  } else {
    delay(300);
    motorSpeed = 0;
  }
}

void obstacles() {
  int numBlocks = pixy.ccc.getBlocks();
  bool obstacleFound = false;

  if (numBlocks) {
    for (int i = 0; i < numBlocks; i++) {

      if (servoAngle > servoLeft || servoAngle < servoRight) {
        motorSpeed = 150;
      }

      if (pixy.ccc.blocks[i].m_signature == 1) {
        obstacleFound = true;
        lastColorGreen = true;

        int objectX = pixy.ccc.blocks[i].m_x;
        int objectWidth = pixy.ccc.blocks[i].m_width;

        if (objectWidth > 100) {
          motorSpeed = 120;
        } else {
          motorSpeed = 130;
        }

        if (left_laser < 8) {
          servoAngle = servoRight - 3;
          return;
        } else if (right_laser < 8) {
          servoAngle = servoLeft + 3;
          return;
        }

        if (laser_right < 12) {
          servoAngle = servoLeft + 3;
        }

        else {
          //servoAngle = map(objectX, 20, 300, servoRight - 8, servoNeutral + 5);
          servoAngle = map(objectX, 20, 300, servoRight - 8, servoNeutral);
          servoAngle = constrain(servoAngle, servoRight, servoLeft);
        }
        break;
      }

      else if (pixy.ccc.blocks[i].m_signature == 2) {
        obstacleFound = true;
        lastColorGreen = false;

        int objectX = pixy.ccc.blocks[i].m_x;
        int objectWidth = pixy.ccc.blocks[i].m_width;

        if (objectWidth > 100) {
          motorSpeed = 120;
        } else {
          motorSpeed = 130;
        }

        if (left_laser < 8) {
          servoAngle = servoRight - 3;
          return;
        } else if (right_laser < 8) {
          servoAngle = servoLeft + 3;
          return;
        }

        if (laser_left < 12) {
          servoAngle = servoRight - 3;
        }

        else {
          //servoAngle = map(objectX, 300, 20, servoNeutral - 5, servoLeft + 8);
          servoAngle = map(objectX, 300, 20, servoNeutral, servoLeft + 8);
          servoAngle = constrain(servoAngle, servoRight, servoLeft);
        }
        break;
      } else {
        pid();
      }
    }
  }

  if (!obstacleFound) {
    pid();
  }

  servoRotate.write(servoAngle);
}
