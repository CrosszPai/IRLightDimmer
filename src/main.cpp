#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

// An IR detector/demodulator is connected to GPIO pin 14(D5 on a NodeMCU
// board).
const uint16_t kRecvPin = 14;

IRrecv irrecv(kRecvPin);

decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();  // Start the receiver
  while (!Serial)  // Wait for the serial connection to be establised.
    delay(50);
  Serial.println();
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin ");
  Serial.println(kRecvPin);
  Serial.println(results.decode_type);
  analogWrite(12,0);
}

void loop() {
  if (irrecv.decode(&results)) {
    if(results.value ==  0xa93){
      analogWrite(12,255);
    }
    if(results.value ==  0xa92){
      analogWrite(12,128);
    }
    if(results.value ==  0xa91){
      analogWrite(12,32);
    }
    if(results.value == 0xa90){
      analogWrite(12,0);
    }
    irrecv.resume();  // Receive the next value
  }
  delay(100);
}
