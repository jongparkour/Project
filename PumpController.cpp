#include "PumpController.h"
#include "SensorManager.h" 

void initializeRelay() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

bool evaluatePumpState(int waterLevel, int turbidity) {
  static bool pumpIsOn = false;  

  if (!pumpIsOn) {
    if (waterLevel <= WATER_LEVEL_ON_THRESHOLD && turbidity >= TURBIDITY_ON_THRESHOLD) {
      pumpIsOn = true;
    }
  } else {
    if (waterLevel >= WATER_LEVEL_OFF_THRESHOLD || turbidity <= TURBIDITY_OFF_THRESHOLD) {
      pumpIsOn = false;
    }
  }

  return pumpIsOn;
}


void updatePumpState(bool pumpOn) {
  digitalWrite(RELAY_PIN, pumpOn ? LOW : HIGH);
  delay(10);
  Serial.print("Water Level: "); Serial.print(analogRead(WATER_LEVEL_PIN));
  Serial.print(" | Turbidity: "); Serial.print(analogRead(TURBIDITY_PIN));
  Serial.print(" | Pump: "); Serial.println(pumpOn ? "ON" : "OFF");
}
