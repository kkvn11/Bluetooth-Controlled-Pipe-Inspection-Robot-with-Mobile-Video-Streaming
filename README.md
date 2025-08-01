# 🧽 Pipeline Inspection and Cleaning Robot

This project presents a self-driven, modular **pipeline cleaning and inspection robot**, designed to operate in confined industrial piping systems. It leverages embedded control, sensor integration, and mechanical innovation to automate the detection and cleaning of internal contaminants, blockages, and damages in pipelines.

Originally developed for the 10th "Hengtuo·Luang Cup" Circuit Design Contest, this system combines affordability, compact size, and extensibility, making it suitable for various use cases like urban drainage, industrial piping inspection, and HVAC maintenance.

---

## 🚀 Features

- 📷 Real-time wireless video transmission and display via mobile app
- 📱 Bluetooth control via Android-based smartphone
- 💪 Adjustable clamping mechanism using lead screw and DC gear motors
- 🌡️ Onboard temperature & humidity monitoring via 18B20 sensor
- 📈 Pressure sensing using strain gauge in Wheatstone bridge configuration
- 🔁 Autonomous bidirectional movement with position feedback
- 🔌 Low-power design, powered by a 12V lithium battery

---

## 🛠 Hardware Overview

| Module | Description |
|--------|-------------|
| MCU    | MC9S12XS128 microcontroller |
| Motor  | 3x DC Gear Motors (50 rad/min) with lead screws |
| Sensors| Pressure sensor + HX711 ADC, 18B20 Temp sensor |
| Wireless| HC-05 Bluetooth + WiFi Camera |
| Power  | LM2596 voltage regulator, 12V lithium battery |
| Structure| Modular clamping arms, compact shell, flexible mechanics |

---

## 💻 Software Structure

- Language: C
- IDE: Keil μVision5
- Control Logic:
  - Sensor data acquisition
  - Motor control and direction switching
  - Wireless communication (Bluetooth + NRF24L01)
  - Real-time feedback to user interface
- Key Modules:
  - `yali1()`, `a_zhang()`, `b_houtui()`, etc.
  - Communication loop via `SCI_receive()`

```c
lanyachushihua();
PWM_initial();   // Initialize PWM
yali1();         // Read pressure sensor
lanyachushihua();
while(1) {
  lanya = SCI_receive();
  if (lanya == '1') {
    a_zhang();   // Activate forward movement
    while (hx1 > 6800000) yali1();
    a_ting();    // Stop motor
  }
}
