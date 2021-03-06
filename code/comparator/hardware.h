#ifndef _HARDWARE_H_
#define _HARDWARE_H_

// Kompas Hardware

#define clockInState PINB&B00100000
#define resetInState PINB&B00010000

// Port mapping for outputs Longitude, altitude, latitude
#define trigOut0 PINB&B00001000
#define trigOut1 PINB&B00000100
#define trigOut2 PINB&B00000010

// unused pins (see expander header on bottom board)
#define PB0 PINB&B00000001
#define PD7 PIND&B10000000

// Mapping of LEDs
int clock_led = 2;
int reset_led = 4;
int led0 = 3;
int led1 = 5;
int led2 = 6;

// expander pin for Boot Settings
#define bootPin PINB&B00000001

#endif
