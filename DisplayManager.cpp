#include "DisplayManager.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define OLED_ADDRESS  0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void initializeDisplay() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    while (1);
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
}

void scrollIntroMessage(String message) {
  Serial.println("Scrolling intro...");

  int messageWidth = message.length() * 10; 
  display.setTextSize(2);

  for (int i = SCREEN_WIDTH; i > -messageWidth; i--) {
    display.clearDisplay();
    display.setCursor(i, 0);
    display.print(message);
    display.display();
    delay(20);
  }

  display.clearDisplay();
  display.setTextSize(2);
}

void displaySensorData(int waterLevel, int turbidity, bool pumpOn) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);

  int waterPercent = map(waterLevel, 20, 400, 0, 105);
  waterPercent = constrain(waterPercent, 0, 105);

  int turbidityPercent = map(turbidity, 655, 15, 0, 100);
  turbidityPercent = constrain(turbidityPercent, 0, 100);

  display.print("Water: ");
  display.print(waterPercent);
  display.println("%");

  display.print("Turb: ");
  display.print(turbidityPercent);
  display.println("%");

  display.print("Pump: ");
  display.println(pumpOn ? "ON" : "OFF");

  display.display();
}