// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// SD Card - Confirm Pin
#define SDpin 53

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);  // wait for serial port to connect. Needed for native USB port only
  }

  // SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDpin)) {
    Serial.println("initialization failed!");
    while (1)
      ;
  }
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
