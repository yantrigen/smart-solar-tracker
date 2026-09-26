Smart Solar Tracker
📌 Overview
The Smart Solar Tracker is an IoT-enabled hardware and software solution designed to maximize solar panel efficiency by adjusting its angle to face the sun directly. This repository contains the complete firmware for the microcontroller, the Android application source code, and the electrical schematics required to build and operate the tracker.

The system is controlled via a custom Android application that communicates with the hardware over Bluetooth/Wi-Fi, providing real-time positional control and monitoring.

✨ Features
Precise Angle Control: A manual slider allows users to set the solar panel to any specific angle between 0° and 180°[cite: 1].

Fine-Tuning: Increment (+1°) and decrement (-1°) buttons for micro-adjustments[cite: 1].

Quick Presets: One-tap positioning for Morning (0°), Noon (90°), and Evening (180°)[cite: 1].

Emergency Override: A dedicated "STOP MOTOR" button instantly halts all mechanical movement in case of hardware malfunction or emergency[cite: 1].

Real-time UI Feedback: The app interface dynamically displays the currently selected angle[cite: 1].

📂 Repository Structure

Smart-Solar-Tracker/
│
├── Arduino_Code/               # Microcontroller firmware (.ino files)
├── App/                        # MIT App Inventor project (.aia) and Android app (.apk)
├── Schematics/                 # Circuit diagrams and wiring guides
├── Docs/                       # Component list, flowcharts, and project reports
├── README.md                   # Project documentation
└── LICENSE                     # Open-source license (MIT)
  
  🛠️ Hardware Requirements
Microcontroller: Arduino UNO, Nano, or ESP32

Actuator: Servo Motor (e.g., SG90, MG995, or linear actuator with motor driver)

Wireless Module: HC-05 Bluetooth Module (if using standard Arduino)

Power Supply: 5V/12V DC power source appropriate for the motors

Structural Frame: 3D printed or wooden chassis for the solar panel

💻 Software Requirements
Arduino IDE: To compile and upload the firmware.

MIT App Inventor: To modify the .aia source file if UI changes are needed.

🚀 Installation & Setup
1. Hardware Setup
Assemble the mechanical frame and mount the servo motor.

Wire the components according to the diagram provided in the Schematics/ directory.

Ensure common ground is established between the microcontroller, motor power supply, and wireless module.

2. Firmware Upload
Open Arduino_Code/smart_solar_tracker.ino in the Arduino IDE.

Install any required libraries (e.g., <Servo.h>, <SoftwareSerial.h>).

Select your designated board and COM port.

Click Upload. (Note: Disconnect the HC-05 RX/TX pins while uploading code to an Arduino Uno).

3. Mobile App Installation
Transfer App/Smart_Solar_Tracker.apk to your Android device.

Enable "Install from Unknown Sources" in your device settings.

Install the application.

📱 Usage Instructions
Power on the solar tracker hardware.

Open your Android device's Bluetooth settings and pair with the HC-05 module (Default PIN is usually 0000 or 1234).

Open the Smart Solar Tracker app.

Tap the Bluetooth Connect button (if configured) to establish a connection.

Use the Slider, Fine-Tuning Buttons, or Quick Presets to adjust the angle[cite: 1].

Tap Set Panel Angle to transmit the command to the hardware[cite: 1].

Use the red STOP MOTOR button to halt operations immediately if necessary[cite: 1].
