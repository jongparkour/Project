#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "config.h"
#include "display.h"

// Create display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void displayInit() {
  display.begin(SSD1306_I2C_ADDRESS, OLED_RESET);
  display.clearDisplay();
}

void welcomeMessage() {
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Solar-Powered Solutions for Efficient Water Distribution");
  display.display();
  delay(2000); // Display for 2 seconds

  // Transition effect: Fade out
  for (int i = 255; i >= 0; i -= 5) {
    display.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.println("Welcome!");
    display.setTextColor(i); // Change text color to create fade effect
    display.display();
    delay(20);
  }

  display.clearDisplay();
}

void displaySensorData(int waterLevel, int turbidity) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  display.print("Water Level: ");
  display.println(waterLevel);

  display.print("Turbidity: ");
  display.println(turbidity);

  display.display();
}
