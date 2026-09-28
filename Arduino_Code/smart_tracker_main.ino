#include <Servo.h>
#include <SoftwareSerial.h>

// Bluetooth Module Pins (HC-05)
// RX pin 10 par, TX pin 11 par (Arduino UNO)
SoftwareSerial bt(10, 11); 

Servo trackerServo;

int ldrEast = A0;
int ldrWest = A1;
int servoPin = 9;
int currentAngle = 90;
int threshold = 20;

// Ye variable batayega ki tracker Auto mode me hai ya Manual
boolean isAutoMode = true; 

void setup() {
  Serial.begin(9600);       // PC Serial Monitor ke liye
  bt.begin(9600);           // Bluetooth communication ke liye
  
  trackerServo.attach(servoPin);
  trackerServo.write(currentAngle);
  
  Serial.println("System Started. Mode: AUTO");
  delay(1000);
}

void loop() {
  // 1. Bluetooth se App ka data check karein
  if (bt.available() > 0) {
    String command = bt.readStringUntil('\n'); 
    command.trim(); // Faltu spaces hatane ke liye

    if (command == "AUTO") {
      isAutoMode = true;
      Serial.println("Mode Changed to: AUTO (LDR Tracking)");
    } 
    else if (command == "STOP") {
      isAutoMode = false;
      Serial.println("Emergency STOP. Mode: MANUAL");
      // Motor jahan hai wahi ruk jayegi
    }
    else {
      // Agar App se koi number (angle) aata hai, toh Manual mode chalu karein
      int angle = command.toInt();
      
      // Check karein ki angle 0 se 180 ke beech hai
      if (angle >= 0 && angle <= 180) {
        isAutoMode = false; // LDR control band kar dein
        currentAngle = angle;
        trackerServo.write(currentAngle);
        
        Serial.print("Mode: MANUAL | Angle Set To: ");
        Serial.println(currentAngle);
      }
    }
  }

  // 2. Agar Auto Mode ON hai, tabhi LDRs apna kaam karenge
  if (isAutoMode) {
    int valueEast = analogRead(ldrEast);
    int valueWest = analogRead(ldrWest);
    int difference = abs(valueEast - valueWest);

    if (difference > threshold) {
      if (valueEast > valueWest && currentAngle > 0) {
        currentAngle--;
        trackerServo.write(currentAngle);
      } 
      else if (valueWest > valueEast && currentAngle < 180) {
        currentAngle++;
        trackerServo.write(currentAngle);
      }
    }
    delay(50); // Servo movement ko smooth aur slow rakhne ke liye delay
  }
}
