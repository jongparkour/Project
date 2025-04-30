#ifndef PUMP_CONTROLLER_H
#define PUMP_CONTROLLER_H

#include <Arduino.h>

#define RELAY_PIN 2

#define WATER_LEVEL_ON_THRESHOLD 20
#define WATER_LEVEL_OFF_THRESHOLD 370
#define TURBIDITY_ON_THRESHOLD 800
#define TURBIDITY_OFF_THRESHOLD 790

void initializeRelay();
bool evaluatePumpState(int waterLevel, int turbidity);
void updatePumpState(bool pumpOn);

#endif