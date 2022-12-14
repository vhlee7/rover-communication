#include <Arduino.h>
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

char msg[6];
RF24 radio(12,14);
const uint64_t pip = 0xE8E8F0F0E1LL;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
 radio.begin();
 radio.setChannel(2);
 radio.setPayloadSize(7);
 radio.setDataRate(RF24_250KBPS);
 radio.openReadingPipe(1,pip);
 radio.startListening();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (radio.available()){  
     Serial.println("Reading message");
     radio.read(msg, 6);      
     Serial.println(msg);
     delay(500);
 }
 else{
  Serial.println("No radio available");
  delay(500);
 }
}