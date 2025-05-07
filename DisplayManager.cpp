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

void displaySensorData(int waterLevel, int turbidity, bool pumpOn) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);

  int waterPercent = map(waterLevel, 40, 450, 0, 100);
  waterPercent = constrain(waterPercent, 0, 100);

  int turbidityPercent = map(turbidity, 650, 120, 0, 100);
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

  delay(100);
}

void drawCuteSquareEye(int x, int y) {
  int eyeSize = 35;
  display.fillRoundRect(x, y, eyeSize, eyeSize, 6, SSD1306_WHITE);
}

void showRoboticEyeIntro() {
  // Move eyes from far left to far right smoothly (60 FPS ~ 16ms per frame)
  for (int offset = 0; offset >= -40; offset -= 14) {
    display.clearDisplay();
    drawCuteSquareEye(30 + offset, 15);  // Left eye
    drawCuteSquareEye(68 + offset, 15);  // Right eye
    display.display();
    delay(16);  // ~60 FPS
  }

  delay(1000);

  for (int offset = -40; offset <= 35; offset += 20) {
    display.clearDisplay();
    drawCuteSquareEye(30 + offset, 15);  // Left eye
    drawCuteSquareEye(68 + offset, 15);  // Right eye
    display.display();
    delay(16);  // ~60 FPS
  }

  delay(100);

  for (int offset = 35; offset >= -30; offset -= 14) {
    display.clearDisplay();
    drawCuteSquareEye(30 + offset, 15);  // Left eye
    drawCuteSquareEye(68 + offset, 15);  // Right eye
    display.display();
    delay(16);  // ~60 FPS
  }

  delay(2000);

  for (int offset = -30; offset <= 20; offset += 20) {
    display.clearDisplay();
    drawCuteSquareEye(30 + offset, 15);  // Left eye
    drawCuteSquareEye(68 + offset, 15);  // Right eye
    display.display();
    delay(16);  // ~60 FPS
  }

  // Blink twice
  for (int b = 0; b < 2; b++) {
    display.clearDisplay();
    display.fillRoundRect(30, 15 + 14, 34, 6, 3, SSD1306_WHITE);  // Left eye closed line
    display.fillRoundRect(68, 15 + 14, 34, 6, 3, SSD1306_WHITE);  // Right eye closed line
    display.display();
    delay(50);

    display.clearDisplay();
    drawCuteSquareEye(30, 15);
    drawCuteSquareEye(68, 15);
    display.display();
    delay(50);
  }

  // Final resting eyes with happy personality
  display.clearDisplay();
  drawCuteSquareEye(28, 15);
  drawCuteSquareEye(70, 15);
  display.display();
}