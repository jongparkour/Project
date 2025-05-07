#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void initializeDisplay();
void displaySensorData(int waterLevel, int turbidity, bool pumpOn);
void drawCuteSquareEye(int x, int y);
void showRoboticEyeIntro();


#endif