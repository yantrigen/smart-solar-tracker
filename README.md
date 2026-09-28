# 🌞 Dual-Mode Smart Solar Tracker

A Smart Solar Tracker project that automatically tracks the sun using LDR sensors and can also be manually controlled via an Android App using an HC-05 Bluetooth module.

## 🚀 Features
- **Auto Mode:** Automatically tracks the light source using two LDR sensors.
- **Manual Mode:** Control the solar panel angle (0° to 180°) manually using a custom Android app.
- **Emergency Stop:** Immediately stops the servo motor movement.
- **Presets:** Quick buttons for Morning (0°), Noon (90°), and Evening (180°).

## 🛠️ Components Required
- Arduino UNO
- Servo Motor (SG90 or MG995)
- 2x LDR (Light Dependent Resistors)
- HC-05 Bluetooth Module
- 10k Resistors (for LDR voltage divider)
- Solar Panel (Dummy or Real for testing)

## 🔌 Pin Connections (Circuit)
| Component | Arduino Pin |
| :--- | :--- |
| **Servo Motor (Signal)** | Pin 9 |
| **East LDR** | Analog Pin A0 |
| **West LDR** | Analog Pin A1 |
| **HC-05 TX** | Pin 10 (SoftwareSerial RX) |
| **HC-05 RX** | Pin 11 (SoftwareSerial TX - Use Voltage Divider) |

## 📱 How to Use the App
1. Download and install the `Smart_Solar_Tracker_v2.apk` from the **App** folder.
2. Turn on Bluetooth on your phone and pair the **HC-05** module (Default PIN: 1234 or 0000).
3. Open the app, click on **Connect**, and select the HC-05 device.
4. Use the slider, +1/-1 buttons, or Quick Presets to control the panel manually.
5. Send the "AUTO" command to switch back to LDR tracking mode.
