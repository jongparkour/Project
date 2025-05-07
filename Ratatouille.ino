#include "DisplayManager.h"
#include "SensorManager.h"
#include "PumpController.h"

void setup() {
  initializeSerial();
  initializeRelay();
  initializeDisplay();
  showRoboticEyeIntro();
}

void loop() {
  int waterLevel = getAverageReading(WATER_LEVEL_PIN);
  int turbidity = getAverageReading(TURBIDITY_PIN);

  bool pumpOn = evaluatePumpState(waterLevel, turbidity);
  updatePumpState(pumpOn);
  displaySensorData(waterLevel, turbidity, pumpOn);

  delay(100);
}