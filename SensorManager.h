#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#include <Arduino.h>

#define WATER_LEVEL_PIN   A0
#define TURBIDITY_PIN     A1

int getAverageReading(int pin, int samples = 10);
void initializeSerial();

#endif