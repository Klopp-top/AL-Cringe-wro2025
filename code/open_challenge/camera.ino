unsigned long lastCountTime = 0;

void getDataFromCam() {
  int i;
  pixy.ccc.getBlocks();

  if (turnCount < 12) {
    if (pixy.ccc.numBlocks) {

      for (i = 0; i < pixy.ccc.numBlocks; i++) {
        Serial.print("  блок ");
        Serial.print(i);
        Serial.print(": ");
        pixy.ccc.blocks[i].print();

        if (pixy.ccc.blocks[i].m_signature == 3) {
          Serial.print("Общее количество сигнатур 3: ");
          Serial.println(turnCount);
          if (millis() - lastCountTime >= 400) {
            lastCountTime = millis();
            turnCount++;
          }
        }
      }
    }
  } else {
    motorSpeed = 0;
  }
}
