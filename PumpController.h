#ifndef PUMP_CONTROLLER_H
#define PUMP_CONTROLLER_H

#include <Arduino.h>

#define RELAY_PIN 2

#define WATER_LEVEL_ON_THRESHOLD 40
#define WATER_LEVEL_OFF_THRESHOLD 450
#define TURBIDITY_ON_THRESHOLD 650
#define TURBIDITY_OFF_THRESHOLD 600

void initializeRelay();
bool evaluatePumpState(int waterLevel, int turbidity);
void updatePumpState(bool pumpOn);

#endif