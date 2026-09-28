/*
 * Smart Solar Tracker v2 - Configuration File
 * Here you can update your network credentials and hardware pin details.
 */

#ifndef CONFIG_H
#define CONFIG_H

// ==========================================
// 1. WiFi Settings (For ESP32 / NodeMCU)
// ==========================================
const char* WIFI_SSID = "YOUR_WIFI_NAME";         // Enter your Wi-Fi SSID here
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD"; // Enter your Wi-Fi Password here

// ==========================================
// 2. Hardware Pin Definitions
// ==========================================
// Pin numbers for ESP32 (Change these according to your specific board setup)
const int SERVO_PIN = 13;      // Servo motor signal pin (ESP32 GPIO 13)
const int BT_RX_PIN = 16;      // Bluetooth RX pin (ESP32 RX2)
const int BT_TX_PIN = 17;      // Bluetooth TX pin (ESP32 TX2)

// ==========================================
// 3. Default Tracker Settings
// ==========================================
const int DEFAULT_ANGLE = 90;  // Default angle of the solar panel on startup
const int MAX_ANGLE = 180;     // Maximum safe rotation angle limit
const int MIN_ANGLE = 0;       // Minimum safe rotation angle limit

#endif
