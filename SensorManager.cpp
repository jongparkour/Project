#include "SensorManager.h"

void initializeSerial() {
  Serial.begin(9600);
  delay(1);
}

int getAverageReading(int pin, int samples) {
  long sum = 0;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(pin);
    delay(5);
  }
  return sum / samples;
}