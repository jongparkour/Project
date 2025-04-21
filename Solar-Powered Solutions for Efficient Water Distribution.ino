//Solar-Powered Solutions for Efficient Water Distribution
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


// Define the I2C address for the OLED display
#define SSD1306_I2C_ADDRESS 0x3C  // or 0x3D depending on your display


#define RELAY_PIN 2
#define WATER_LEVEL_PIN A0
#define TURBIDITY_PIN A1


#define THRESHOLD 100  // Set your desired threshold value for water level
#define ACCEPTABLE_LEVEL 200  // Set your desired acceptable turbidity level


void setup() {
  pinMode(RELAY_PIN, OUTPUT);
 
  // Initialize OLED display
  display.begin(SSD1306_I2C_ADDRESS, OLED_RESET);
  display.clearDisplay();
 
  // Display welcome message with transition effect
  welcomeMessage();
}


void loop() {
  int waterLevel = analogRead(WATER_LEVEL_PIN);
  int turbidity = analogRead(TURBIDITY_PIN);
 
  // Logic to control the pump based on sensor readings
  if (waterLevel < THRESHOLD && turbidity < ACCEPTABLE_LEVEL) {
    digitalWrite(RELAY_PIN, HIGH); // Turn on pump
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turn off pump
  }
 
  // Update OLED display with sensor readings
  displaySensorData(waterLevel, turbidity);
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
