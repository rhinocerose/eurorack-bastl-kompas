#ifndef _HARDWARE_H_
#define _HARDWARE_H_

//Kompas Hardware

#define clockIn PIND&B10000000
#define resetIn PINB&B00000001

//un-comment for turning CV inputs into individual reset inputs
//#define resetIn0 PINC&B00000001
//#define resetIn1 PINC&B00000010
//#define resetIn2 PINC&B00000100

//Port mapping for outputs Longitude, altitude, latitude
#define trigOut0 PIND&B00001000 // PD3
#define trigOut1 PIND&B00100000 // PD5
#define trigOut2 PINB&B00000010 // PB1

//unused pins (see expander header on bottom board)
#define PB4 PINB&B00010000
#define PB5 PINB&B00100000

// Mapping of LEDs
int clock_led = 2;
int reset_led = 4;
int led2 = 6;
int led1 = 10;
int led0 = 11;

//expander pin for Boot Settings
#define bootPin PINB&B00010000

#endif
