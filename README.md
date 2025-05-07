# 🌞 Solar-Powered Solutions for Efficient Water Distribution

## 📘 Introduction

**Solar-Powered Solutions for Efficient Water Distribution** is a solar-powered, Arduino-based water management system designed to provide an efficient and sustainable solution for communities in remote, mountainous areas where water access is limited. The system automates water pumping, monitors water levels to prevent overflow, and continuously tracks water quality using a turbidity sensor. Data is displayed in real-time on an OLED screen, and the system is housed in a compact casing for field readiness. The project demonstrates the system's ability to lift water to a height of one meter using renewable solar energy. Future upgrades include integrating a pH sensor and a GSM module for wireless monitoring and SMS notifications.

---

## ⚙️ Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/solar-water-distribution.git
   cd solar-water-distribution
   ```

2. Open the Arduino sketch (`main.ino`) using the **Arduino IDE**.

3. Install the required libraries:
   - `Adafruit_GFX`
   - `Adafruit_SSD1306`
   - `SoftwareSerial` (for GSM, if implemented)

4. Set the board to **Arduino Uno** and select the correct COM port.

5. Upload the code to your Arduino board.

---

## 🔧 Components Used

| Component                | Quantity | Estimated Price (₱) |
|--------------------------|----------|---------------------|
| Arduino Uno              | 1        | 600.00              |
| 12V Water Pump           | 1        | 150.00              |
| 16W Solar Panel          | 1        | 650.00              |
| Adjustable Regulator     | 1        | 150.00              |
| Turbidity Sensor         | 1        | 400.00              |
| Water Level Sensor       | 1        | 100.00              |
| 5V Relay Module          | 1        | 150.00              |
| 0.96 inch OLED Display   | 1        | 150.00              |
| Breadboard               | 1        | 100.00              |
| Jumper Wires             | 1 set    | 70.00               |
| Plastic Hose             | 1        | 40.00               |

**Estimated Total:** ₱2,560.00

---

## 🧐 System Architecture

- Water level and turbidity sensors collect data.
- Arduino Uno processes sensor input and controls the relay.
- If the tank is not full and water quality is acceptable, the pump is activated.
- OLED display shows turbidity and water level status.
- The system runs on solar power via a 16W solar panel and voltage regulator.

---

## 🔌 Wiring Diagram

![image](https://github.com/user-attachments/assets/014f5b1b-7241-400a-981f-572916c7532f)

## 📊 How It Works

- Turbidity is measured in NTU and displayed on the OLED screen.
- If the water tank is full, the pump stops automatically.
- Data is updated live, providing feedback on system performance.

---

## 🌟 Expected Outcomes

- Water successfully lifted to 1-meter height using solar energy.
- Reliable detection of water quality and level.
- Real-time visual monitoring with OLED display.
- Modular system architecture allows for future upgrades.

---

## 🚀 Future Enhancements

- 📡 **GSM Module**: Send SMS alerts for water status.
- 🧪 **pH Sensor**: Monitor water acidity.
- 📦 **Weatherproof Housing**: For long-term outdoor deployment.
- 💧 **Flow Rate Sensor**: For volume-based water usage tracking.

---

## 👥 Contributors

- **Jesbril Duhig** – [jesbrilg.duhig@gmail.com](mailto:jesbrilg.duhig@gmail.com)  
- **Louis Carpio** – [carpiolouis922@gmail.com](mailto:carpiolouis922@gmail.com)  
- **Jhunathan Endab** – [jhunathanendab@gmail.com](mailto:jhunathanendab@gmail.com)  
- **Joseph Erl Libosada** – [libosadajosephy@gmail.com](mailto:libosadajosephy@gmail.com)

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).

---

## 📷 Media

![image](https://github.com/user-attachments/assets/6603edcb-6a3e-4e8d-9b13-27a70fda499c)

---

## 📁 Keywords

solar power, automated water flow, water quality monitoring, turbidity detection, reservoir management, mountainous regions, water scarcity, sustainable technology, OLED display, automatic water level control, compact design, pH sensor, GSM module, SMS alerts
