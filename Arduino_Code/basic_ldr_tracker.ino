#include <Servo.h>

Servo trackerServo;  // Servo motor ka object banaya

// LDR pins define karein (Analog pins)
int ldrEast = A0;    // East side ka LDR pin
int ldrWest = A1;    // West side ka LDR pin

int servoPin = 9;    // Servo motor ka PWM pin
int currentAngle = 90; // Shuruati angle 90 degrees rakha hai (Panel bilkul upar)
int threshold = 20;  // Sensitivity (choti light changes/shadows ko ignore karne ke liye)

void setup() {
  Serial.begin(9600);
  trackerServo.attach(servoPin);  // Servo ko pin 9 se connect kiya
  trackerServo.write(currentAngle); // Servo ko starting me center (90°) par set kiya
  delay(2000);
}

void loop() {
  // Dono LDRs ki value read karein (0 se 1023 ke beech)
  int valueEast = analogRead(ldrEast);
  int valueWest = analogRead(ldrWest);

  // Serial Monitor par values print karne ke liye (testing ke liye)
  Serial.print("East LDR: ");
  Serial.print(valueEast);
  Serial.print(" | West LDR: ");
  Serial.println(valueWest);

  // Dono LDR ki light ka difference nikalein
  int difference = abs(valueEast - valueWest);

  // Agar difference threshold se zyada hai, tabhi motor ghumegi
  if (difference > threshold) {
    
    // Agar East LDR par dhoop zyada hai, toh angle kam karein (0° ki taraf)
    if (valueEast > valueWest) {
      if (currentAngle > 0) {
        currentAngle--; // Angle 1 degree kam karein
        trackerServo.write(currentAngle);
      }
    }
    // Agar West LDR par dhoop zyada hai, toh angle badhayein (180° ki taraf)
    else if (valueWest > valueEast) {
      if (currentAngle < 180) {
        currentAngle++; // Angle 1 degree badhayein
        trackerServo.write(currentAngle);
      }
    }
  }

  // Motor ko smooth chalne ke liye thoda delay dein
  delay(50);
}
