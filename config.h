#ifndef CONFIG_H
#define CONFIG_H

#define RELAY_PIN 2
#define WATER_LEVEL_PIN A0
#define TURBIDITY_PIN A1

#define THRESHOLD 100  // Set your desired threshold value for water level
#define ACCEPTABLE_LEVEL 200  // Set your desired acceptable turbidity level

// OLED Display
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SSD1306_I2C_ADDRESS 0x3C  // or 0x3D depending on your display

#endif
