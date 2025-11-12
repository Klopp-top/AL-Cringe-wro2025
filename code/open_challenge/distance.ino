void getSonicDistance(){
  delay(50);

  unsigned int uS1 = left.ping();
  distance_left = uS1 / US_ROUNDTRIP_CM;

  unsigned int uS2 = right.ping();
  distance_right = uS2 / US_ROUNDTRIP_CM;

  if (distance_left == 0) distance_left = MAX_DISTANCE;
  if (distance_right == 0) distance_right = MAX_DISTANCE;

//  Serial.print("L: ");
//  Serial.print(distance_left);
//  Serial.print(" cm   R: ");
//  Serial.print(distance_right);
//  Serial.println(" cm");
}

void getLaserDistance() {
  laser_right = sensor_right.readRangeContinuousMillimeters() / 10;
  laser_center = sensor_center.readRangeContinuousMillimeters() / 10;
  laser_left = sensor_left.readRangeContinuousMillimeters() / 10;

//    Serial.print(laser_right);
//    Serial.print("     ");
//    Serial.print(laser_center);
//    Serial.print("     ");
//    Serial.println(laser_left);
}
