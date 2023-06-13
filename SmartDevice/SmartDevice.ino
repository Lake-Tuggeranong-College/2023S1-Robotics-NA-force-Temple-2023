// SD Card Module
#include <SPI.h>
#include <SD.h>

// SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }

// Real Time Clock (RTC)
rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
Serial.println("initialization done.");
logEvent("System Initialisation...");

// SD Card - Confirm Pin
#define SDPIN 53

//trafic lights
#define LEDRED A2
#define LEDYELLOW A1 
#define LEDGREEN A0

//DC motor
#include <L298N.h>

// Pin definition
const unsigned int IN1 = 7;
const unsigned int IN2 = 8;
const unsigned int EN = 9;

// Create one motor instance
L298N motor(EN, IN1, IN2);

// Servo
#include <Servo.h>
Servo myservo;

//Potentiometer
#define POT A3

// Piezo Buzzer
#define piezoPin 5

// Sonar - HC-SR04
#define echoPin A4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 53 //attach pin D3 Arduino to pin Trig of HC-SR04

// Line Sensor
#define lineSensorPin 3

// Crash Sensor / Button
#define crashSensor 7

// RFID Start

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN  21  // ES32 Feather
#define RST_PIN 17 // esp32 Feather - SCL pin. Could be others.

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600); 
}

void loop() {
  forceDoor ();
  delay(250);
}


forceDoor(){

  
}

