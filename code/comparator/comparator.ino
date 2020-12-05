/*
   Alternative window comparator firmware for stziopa/bastl-instruments Kompas hardware
   licensed under CC-BY-SA by Phillip Mates 2020-12-05
*/

#include <EEPROM.h>
#include "hardware.h"
#include "definitions.h"
#include "variables.h"

void setup() {
  Serial.begin(9600);

  // set pins PB7, PB6, PB3 (longitude), PB2 (altitude), PB1 (latitude) as outputs, PB0 as input
  DDRB = B11001110;
  PORTB | B00000001;
  // PB0 internal pullup resistor
  PINB |= B00000001;

  // set pins PD7, PD6, PD5, PD4, PD3, PD2 as outputs, leaves PD1 and PD0 as default (ftdi)
  DDRD = DDRD | B11111100;
  PORTD | B00000000;
  // PD7 High
  PIND |= B10000000;

  pinMode(clock_led, OUTPUT);
  pinMode(reset_led, OUTPUT);

  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // on my hardware the top cv in is A1
  signalCV = analogRead(A1);
  shiftCV = analogRead(A0);
  sizeCV = analogRead(A2);

  // read values from pots
  probPot = analogRead(A3);
  shiftPot = analogRead(A4);
  sizePot = analogRead(A5);

  shift = (shiftPot + shiftCV);
  size = (sizePot + sizeCV);

  top = shift + (size / 2);
  bottom = shift - (size / 2);
  /* Serial.println("shift\t" + String(shift) + "\tsize\t" + String(size) + "\tsignalCV\t" + String(signalCV)); */

  if (signalCV >= bottom && signalCV <= top) {
    if (!inRange) {
      PINB |= B00001000;
    }
    inRange = true;
  } else {
    PORTB &= B11110111;
    inRange = false;
  }

  if (clockInState) {
    if (!inClock) {
      digitalWrite(clock_led, HIGH);
    }
    inClock = true;
  } else {
    digitalWrite(clock_led, LOW);
    inClock = false;
  }

  if (inRange && clockInState) {
    if (!inAnd) {
      PINB |= B00000100;
    }
    inAnd = true;
  } else {
    PORTB &= B11111011;
    inAnd = false;
  }

  if (inRange != (!!clockInState)) {
    if (!inXor) {
      PINB |= B00000010;
    }
    inXor = true;
  } else {
    PORTB &= B11111101;
    inXor = false;
  }
}
