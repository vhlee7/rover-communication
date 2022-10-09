#include <Arduino.h>
#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

char msg[6] = "hello";
RF24 radio(12, 14);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  radio.begin();
  radio.setChannel(2);
  radio.setPayloadSize(7);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(pipe);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("send ...");
  radio.write(msg, 6);
  delay(3000);
}