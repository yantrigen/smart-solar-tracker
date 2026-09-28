/*
 * Smart Solar Tracker v2 - Firmware
 * Author: Shubham Kakasaheb Gaikwad
 * Description: Control a servo motor based on Bluetooth commands (Angle 0-180 or "STOP").
 */

#include <Servo.h>
#include <SoftwareSerial.h>

// --- Pin Definitions ---
const int servoPin = 9;      // Servo motor signal pin
const int btRxPin = 10;      // Bluetooth TX connected to Arduino Pin 10 (RX)
const int btTxPin = 11;      // Bluetooth RX connected to Arduino Pin 11 (TX)

// --- Objects & Variables ---
Servo solarTrackerServo;
SoftwareSerial BTSerial(btRxPin, btTxPin);

int currentAngle = 90;       // Default starting position
bool isEmergencyStop = false;

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
  
  // Initialize Bluetooth Serial
  BTSerial.begin(9600); // Default baud rate for HC-05
  
  // Attach and position servo
  solarTrackerServo.attach(servoPin);
  solarTrackerServo.write(currentAngle);
  
  Serial.println("Smart Solar Tracker Ready!");
  Serial.println("Waiting for Bluetooth commands...");
}

void loop() {
  // Check if data is available from Bluetooth app
  if (BTSerial.available() > 0) {
    // Read the incoming string command
    String command = BTSerial.readString();
    command.trim(); // Remove any accidental spaces or newlines

    if (command.length() > 0) {
      Serial.print("Command Received: ");
      Serial.println(command);

      // --- Logic 1: Emergency STOP Command ---
      if (command == "STOP") {
        isEmergencyStop = true;
        solarTrackerServo.detach(); // Cut signal to motor to stop it completely
        Serial.println("STATUS: EMERGENCY STOP ACTIVATED!");
      } 
      // --- Logic 2: Angle Command (0 to 180) ---
      else {
        // If it was stopped previously, reattach the motor
        if (isEmergencyStop) {
          solarTrackerServo.attach(servoPin);
          isEmergencyStop = false;
          Serial.println("STATUS: MOTOR RE-ACTIVATED.");
        }

        // Convert the string to an integer angle
        int targetAngle = command.toInt();

        // Validate if the angle is within safe limits (0 to 180 degrees)
        if (targetAngle >= 0 && targetAngle <= 180) {
          currentAngle = targetAngle;
          solarTrackerServo.write(currentAngle); // Move motor to new angle
          
          Serial.print("Moving Panel to: ");
          Serial.print(currentAngle);
          Serial.println(" degrees.");
        } else {
          Serial.println("ERROR: Invalid Angle. Please send a value between 0 and 180.");
        }
      }
    }
  }
}
