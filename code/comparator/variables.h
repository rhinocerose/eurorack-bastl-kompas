#ifndef _VARIABLES_H_
#define _VARIABLES_H_


// cv values
int signalCV = 0;
int shiftCV = 0;
int sizeCV = 0;

const int cvMax = 1011;

int range = 0;
bool inRange = 0;
bool inAnd = 0;
bool inClock = 0;

// pot positions
int pot0 = 0;
int shiftPot = 0;
int sizePot = 0;

int top, bottom;
int shift, size;

unsigned long lastClock = 0;
unsigned long lastReset = 0;

bool clockJump;
bool resetJump;

bool clockState;
bool resetState;

byte clock_bounce_counter;
byte reset_bounce_counter;

#endif
