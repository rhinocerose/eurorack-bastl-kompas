/*
   Alternative probabilistic latch / burst firmware for stziopa/bastl-instruments Kompas hardware
   licensed under CC-BY-SA by Phillip Mates 2020-12-11

knobs
-------------
(burst count)  o
(latch A prob) o
(latch B prob) o

jacks
-------------
(burst trigger)     o  |  o   (latch A trigger)
(burst length)      o  |  o   (burst out)
(latch A prob)      o  |  o   (latch A out
(latch B trigger)   o  |  o   (latch B out)
*/

#include <EEPROM.h>
#include "hardware.h"
#include "definitions.h"
#include "variables.h"

void setup() {
  Serial.begin(9600);

  // set pins PB7, PB6, PB3, PB2, PB1  as outputs, PB0 as input
  DDRB = B11001110;
  PORTB | B00000001;
  // PB0 internal pullup resistor
  PINB |= B00000001;

  // set pins PD7, PD6, PD5, PD4, PD3, PD2 as outputs, leaves PD1 and PD0 as default (ftdi)
  DDRD = DDRD | B11111100;
  PORTD | B00000000;
  // PD7 High
  PIND |= B10000000;

  pinMode(burst_in_led, OUTPUT);
  pinMode(latch_a_in_led, OUTPUT);

  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  randomSeed(analogRead(A5));
}

bool latchAOn, latchBOn;
uint8_t burstLengthBase = 100;
uint8_t burstCount, burstsLeft, burstLength;
unsigned long now;

void loop() {
  deLatchATrig();
  deBurstTrig();
  deLatchBTrig();
  latchAOn = trigOut1;
  latchBOn = trigOut2;
  now = millis();

  // on my hardware the top cv in is A1
  burstCV = analogRead(A1);
  latchACV = analogRead(A0);

  // read values from pots
  burstPot = analogRead(A3);
  latchAPot = analogRead(A4);
  latchBPot = analogRead(A5);

  int rnd = random(1011);

  if (latchAState) {
    digitalWrite(latch_a_in_led, HIGH);
    lastLatchA = now;
    if (!(!(trigOut1))) {
      // latch off
      PORTB &= B11111011;
    } else if ((latchAPot + latchACV) > rnd) {
      // latch on
      PINB |= B00000100;
    }
  }
  if (now >= lastLatchA + trigLength) {
    digitalWrite(latch_a_in_led, LOW);
  }

  if (latchBState) {
    lastLatchB = now;
    if (!(!(trigOut2))) {
      // latch off
      PORTB &= B11111101;
    } else if (latchBPot > rnd) {
      // latch on
      PINB |= B00000010;
    }
  }

  burstCount = burstPot / 128;
  burstLength = burstLengthBase + ((burstCV / 64) * burstLengthBase);

  // start bursts
  if (burstState) {
    burstsLeft = burstCount;
    lastBurstIn = now;
    digitalWrite(burst_in_led, HIGH);
  }

  // turn off burst in LED
  if (now >= lastBurstIn + trigLength) {
    digitalWrite(burst_in_led, LOW);
  }

  // trigger a burst
  if ((burstsLeft > 0) && (now >= (lastBurst + burstLength))) {
    lastBurst = now;
    burstsLeft--;
    PINB |= B00001000;
  }

  // shut off a single burst
  if (now >= lastBurst + trigLength) {
      PORTB &= B11110111;
  }
}
