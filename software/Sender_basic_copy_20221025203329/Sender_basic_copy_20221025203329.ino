
#include <Arduino.h>
#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include <cstring>

char msg[6] = "hello";
RF24 radio(22, 21);
const uint64_t pip = 0xE8E8F0F0E1LL;

void setup() {
  // put your setup code here, to run once:
  Serial.println("A thing");
  Serial.begin(9600);
  radio.begin();
  radio.setChannel(2);
  radio.setPayloadSize(16);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(pip);
}

char rx_byte = 0;
String rx_str = "";

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
    
    if (rx_byte != '\n') {
      // a character of the string was received
      rx_str += rx_byte;
    }
    else {
      // end of string
      Serial.println("sending ...");
      const char* str = rx_str.c_str();
      radio.write(str, sizeof(rx_str));
      Serial.println(str);
      Serial.println(sizeof(rx_str));
      rx_str = "";
      // Serial.print("Welcome ");
      // Serial.println(rx_str);
      // rx_str = "";                // clear the string for reuse
      // Serial.println("");
      // Serial.println("Enter your name.");
    }
    // Serial.println("send ...");
    // radio.write(msg, sizeof(msg));
    // Serial.println(msg);
  }
  
    
  
  // Serial.println("send ...");
  // radio.write(msg, sizeof(msg));
  // Serial.println(msg);
  // delay(1000);
}