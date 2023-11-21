#include <Servo.h>

// Function declarations
void openGate(Servo &servo);
void closeGate(Servo &servo);
void playBuzzer();
void blinkYellowLight(int duration, int interval);
void blinkRedLight(int duration, int interval);

// Define pin numbers for components
const int ldrPin = A0;            // LDR sensor analog pin
const int laserBeamPin = 4;       // Laser diode control pin
const int irSensorPin = 5;        // IR Proximity Sensor input pin
const int gateServoPin1 = 6;      // Servo motor control pin for Gate 1
const int gateServoPin2 = 7;      // Servo motor control pin for Gate 2
const int redLightPin = 8;        // Red LED light pin
const int yellowLightPin = 9;     // Yellow LED light pin
const int greenLightPin = 10;     // Green LED light pin
const int buzzerPin = 11;         // Buzzer control pin

Servo gateServo1;
Servo gateServo2;

// Define the threshold value for the LDR
const int thresholdValue = 500;  // Adjust this value as needed


void setup() {
  Serial.begin(9600);

  // Initialize components
  gateServo1.attach(gateServoPin1);
  gateServo2.attach(gateServoPin2);
  pinMode(ldrPin, INPUT);
  pinMode(irSensorPin, INPUT);
  pinMode(laserBeamPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Close both gates initially
  closeGate(gateServo1);
  closeGate(gateServo2);
}

void loop() {
  // Read the IR sensor
  int irValue = digitalRead(irSensorPin);
  digitalWrite(laserBeamPin, LOW);
  
  if (!irValue == HIGH) {
    // IR sensor detected an object, turn on the yellow light
    digitalWrite(laserBeamPin, HIGH);
    
    // Check the LDR value
    int ldrValue = analogRead(ldrPin);
    
    if (ldrValue < thresholdValue) {
      // LDR detected light, open the gate and turn on the green light
      Serial.println("Beam Good.");
      digitalWrite(greenLightPin, HIGH);
      digitalWrite(redLightPin, LOW);  // Turn off the red light
      openGate(gateServo1);
      openGate(gateServo2);
    } else {
      // LDR did not detect light, blink the red light
      Serial.println("Beam Breaking.");
      alart();
      digitalWrite(laserBeamPin, LOW);  // Turn on the laser Beam
      digitalWrite(greenLightPin, LOW);  // Turn off the green light
      blinkRedLight(1000, 500);
      closeGate(gateServo1);
      closeGate(gateServo2);
    }
  } else {
    // No object detected by the IR sensor, blink the yellow light
    digitalWrite(greenLightPin, LOW);
    Serial.println("System Waiting.");
    blinkYellowLight(1000, 500);
    digitalWrite(yellowLightPin, LOW);  // Turn off the yellow light
    closeGate(gateServo1);
    closeGate(gateServo2);
  }
}

void openGate(Servo &servo) {
  servo.write(90); // Open the gate (adjust the angle as needed)
}

void closeGate(Servo &servo) {
  servo.write(0); // Close the gate (adjust the angle as needed)
}

void playBuzzer() {
  // Implement the logic for playing the buzzer here
  // You can use tone() function or other methods
}

void blinkYellowLight(int duration, int interval) {
  digitalWrite(yellowLightPin, HIGH);
  delay(duration);
  digitalWrite(yellowLightPin, LOW);
  delay(interval);
}

void blinkRedLight(int duration, int interval) {
  digitalWrite(redLightPin, HIGH);
  delay(duration);
  digitalWrite(redLightPin, LOW);
  delay(interval);
}
void alart(){
  digitalWrite(buzzerPin, HIGH);
  delay(1000);
  digitalWrite(buzzerPin, LOW);
  delay(200);
}