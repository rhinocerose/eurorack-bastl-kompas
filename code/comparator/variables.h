#ifndef _VARIABLES_H_
#define _VARIABLES_H_

// cv values
int signalCV = 0;
int shiftCV = 0;
int sizeCV = 0;

// window state
int range = 0;
int top, bottom;
int shift, size;
int step, sampleAt;

// track on-state to not retrigger stuff
bool inRange = 0;
bool inAnd = 0;
bool inXor = 0;
bool inClock = 0;

// pot positions
int samplePot = 0;
int shiftPot = 0;
int sizePot = 0;

#endif
