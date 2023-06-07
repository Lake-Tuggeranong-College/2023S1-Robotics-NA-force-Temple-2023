// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

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
  checkDoorBell();
  delay(250);
  senseDistanceFromDoor();
  delay(250);
  determineLightBrightness();
  delay(250);
  determineFanSpeed();
  delay(250);
  determineIfNight();
  delay(250);
}

void logEvent(string dataToLog){
  Date
}
/*
 will determin if the crash button has been presed
 @prams = none
 @return = none
 */
void checkDoorBell(){

}
/*
 will determin if a person is within 5 meters of the door
 @prams = none
 @return = none
 */
void senseDistanceFromDoor(){

}
/*
 will determin how bright the lights will be
 @prams = none
 @return = none
 */
void determineLightBrightness(){

}
/*
 will determin how fast the fan shuld be
 @prams = none
 @return = none
 */
void determineFanSpeed(){

}
/*
 will determin if the sun has set
 @prams = none
 @return = none
 */
void templeLockdown(){
do{
 
}while();
}
/*
 will run the lock down function
 @prams = none
 @return = none
 */

/*
 will check for a RFID card
 @prams = none
 @return = none
 */
void checkForCard(){

}
