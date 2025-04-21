#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
#define OLED_ADDRESS  0x3C  // Default I2C address

// Initialize OLED display
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pin Definitions
#define RELAY_PIN         2
#define WATER_LEVEL_PIN   A0
#define TURBIDITY_PIN     A1

// Thresholds
#define WATER_LEVEL_ON_THRESHOLD 50
#define WATER_LEVEL_OFF_THRESHOLD 450
#define TURBIDITY_ON_THRESHOLD 800  // Turbidity threshold for turning pump on
#define TURBIDITY_OFF_THRESHOLD 790


// Function Prototypes
int getAverageReading(int pin, int samples = 10);
void scrollIntroMessage(String message);
void displaySensorData(int waterLevel, int turbidity, bool pumpOn);

void setup() {
  Serial.begin(9600);
  delay(1); // Let serial and sensors settle

  pinMode(RELAY_PIN, OUTPUT); 
  digitalWrite(RELAY_PIN, LOW); // Ensure pump is OFF initially

  Serial.println("Starting sensor reading...");
  int waterLevel = analogRead(WATER_LEVEL_PIN);
  Serial.println(waterLevel);


  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println(F("OLED allocation failed"));
    while (1); // Halt on error
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  scrollIntroMessage("JESBRIL");
}

void loop() {
  // Read and average sensor data
  int waterLevel = getAverageReading(WATER_LEVEL_PIN);
  int turbidity = getAverageReading(TURBIDITY_PIN);

  // Pump control logic:
  // - Turn ON pump if water level is below 50 and turbidity is 655 (clean water)
  // - Turn OFF pump if water level is above 450 and turbidity is 500 (moderately dirty water)
  bool pumpOn = false; // Default to  pump off

  if (waterLevel < WATER_LEVEL_ON_THRESHOLD && turbidity >= TURBIDITY_ON_THRESHOLD) {
    pumpOn = true; // Turn pump on if water level < 50 and turbidity == 655 (clean water)
  } else if (waterLevel > WATER_LEVEL_OFF_THRESHOLD && turbidity <= TURBIDITY_OFF_THRESHOLD) {
    pumpOn = false; // Turn pump off if water level > 450 and turbidity >= 500 (moderately dirty water)
  }

  digitalWrite(RELAY_PIN, pumpOn ? HIGH : LOW);
  Serial.print("Water Level: "); Serial.print(waterLevel);  
  Serial.print(" | Turbidity: "); Serial.print(turbidity);
  Serial.print(" | Pump: "); Serial.println(pumpOn ? "ON" : "OFF");

  // Update display
  displaySensorData(waterLevel, turbidity, pumpOn);

  delay(5); // Update every second
}

// Smooth sensor data by averaging multiple samples
int getAverageReading(int pin, int samples) {
  long sum = 0;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(pin);
    delay(5); // Small delay between reads
  }
  return sum / samples;
}

// Scroll an introductory message across the screen
void scrollIntroMessage(String message) {
  int messageWidth = message.length() * 10; // Approx. width per character
  display.setTextSize(2);

  // Scroll the message while continuously updating sensor data
  unsigned long startTime = millis();  // Capture the starting time
  while (millis() - startTime < 2000) {  // Show the message for 2 seconds
    for (int i = SCREEN_WIDTH; i > -messageWidth; i--) {
      display.clearDisplay();
      display.setCursor(i, 0);
      display.print(message);
      display.display();
      delay(20); // Scrolling speed
    }
  }

  // After the scrolling is done, continue with the sensor display
  display.clearDisplay();
  display.setTextSize(2);  // Set larger text size for the readings
}

void displaySensorData(int waterLevel, int turbidity, bool pumpOn) {    
  display.clearDisplay();
  display.setTextSize(2.5);
  display.setCursor(0, 0);

  // Convert water level to percentage (8-555 -> 0-100%)
  int waterPercent = map(waterLevel, 10, 540, 0, 105);  // Map from sensor range (8-555) to 0-100%
  waterPercent = constrain(waterPercent, 0, 105); // Constrain to make sure it stays within 0-100%

  // Convert turbidity to percentage with adjusted mapping (300 to 850 for turbidity)
  int turbidityPercent = map(turbidity, 655, 15, 0, 100); // 850 = clean (0%), 300 = dirty (100%)
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
