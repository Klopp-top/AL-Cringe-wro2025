void getColor() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  redFrequency = pulseIn(sensorOut, LOW);
  redColor = map(redFrequency, 50, 120, 255,0);
  delay(1);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);

  greenFrequency = pulseIn(sensorOut, LOW);
  greenColor = map(greenFrequency, 80, 150, 255, 0);

  delay(1);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);

  blueFrequency = pulseIn(sensorOut, LOW);
  blueColor = map(blueFrequency, 45, 60, 255, 0);

  delay(1);


  if (redColor > greenColor && redColor > blueColor) {
    color = "red";
    turnCount + 0.5;
  }
  if (greenColor > redColor && greenColor > blueColor) {
    color = "blue";
    turnCount + 0.5;
  }
  if (blueColor > redColor && blueColor > greenColor) {
    color = "green";
  }
}

void getFirstColor() {
  if (color == "red") {
    redLine = true;
  } else if (color == "blue") {
    redLine = false;
  }
}
