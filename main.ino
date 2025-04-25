#include "config.h"
#include "sensors.h"
#include "display.h"

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  displayInit();
  welcomeMessage();
}

void loop() {
  int waterLevel = readWaterLevel();
  int turbidity = readTurbidity();

  // Logic to control the pump based on sensor readings
  if (waterLevel < THRESHOLD && turbidity < ACCEPTABLE_LEVEL) {
    digitalWrite(RELAY_PIN, HIGH); // Turn on pump
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turn off pump
  }

  displaySensorData(waterLevel, turbidity);
}
