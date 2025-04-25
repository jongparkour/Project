#include <Arduino.h>
#include "config.h"
#include "sensors.h"

int readWaterLevel() {
  return analogRead(WATER_LEVEL_PIN);
}

int readTurbidity() {
  return analogRead(TURBIDITY_PIN);
}
