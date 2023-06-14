// SD Card Module
#include <SPI.h>
#include <SD.h>

// // SD Card initialisation
//   Serial.print("Initializing SD card...");
//   if (!SD.begin(10)) {
//     Serial.println("initialization failed!");
//     while (1);
//   }

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
#define POTPIN A3

// Piezo Buzzer
#define PIEZOPIN 5

// Sonar - HC-SR04
#define ECHOPIN A4 // attach pin D2 Arduino to pin Echo of HC-SR04
#define TRIGPIN 53 //attach pin D3 Arduino to pin Trig of HC-SR04

// Line Sensor
#define LINGSENSORPIN 3

// Crash Sensor / Button
#define CRASHPIN 7

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
  doorLock ();
  delay(250);
  forceDoor();
  delay(250);
  fanControle();
  delay(250);
  determenLight();
  delay(250);
  tripWireAlarm();
  delay(250);
}

void readRFID() {

  String uidOfCardRead = "";
  String validCardUIDWork = "198 128 61 43";  // Change this as needed
  String validCardUIDHome = "00 232 81 25";   // Change this as needed.

  if (rfid.PICC_IsNewCardPresent()) { // new tag is available
    if (rfid.PICC_ReadCardSerial()) { // NUID has been readed
      MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

      for (int i = 0; i < rfid.uid.size; i++) {
        uidOfCardRead += rfid.uid.uidByte[i] < 0x10 ? " 0" : " ";
        uidOfCardRead += rfid.uid.uidByte[i];
      }
      //Serial.println(uidOfCardRead);

      rfid.PICC_HaltA(); // halt PICC
      rfid.PCD_StopCrypto1(); // stop encryption on PCD
      uidOfCardRead.trim();
      if (uidOfCardRead == validCardUIDWork || uidOfCardRead == validCardUIDHome) {
        return true;
      } else {
        return false;
      }
    }
  }
}
/*
will unlock the door(dc moter) if an RFID card is placed upon a sensor
*/
doorLock(){
  if (readRFID == true){
      motor.forward();
    delay(1000);
    motor.stop();
    delay(1000);
    motor.backward();
    delay(1000);

  } 
}
/*
when user gets within a set distance(soner) open the door(servo) 
*/
forceDoor(){

}
/*
determans the speed of the fan(dc moter) based on the pot
*/
fanControle(){

}
/*
switchers the type of light(traffic lights) every time the button is pressed(crash sensor)
*/
determenLight(){

}
/*
sounds an alarm(piezo) if trip wire is set off(line sensor)
*/
tripWireAlarm(){

}