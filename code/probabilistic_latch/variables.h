#ifndef _VARIABLES_H_
#define _VARIABLES_H_

// cv values
int burstCV = 0;
int latchACV = 0;

int latchBTrig = 0;

// pot positions
int burstPot = 0;
int latchAPot = 0;
int latchBPot = 0;

unsigned long lastBurstIn = 0;
unsigned long lastBurst = 0;
unsigned long lastLatchA = 0;
unsigned long lastLatchB = 0;

bool burstJump;
bool latchAJump;
bool latchBJump;

bool burstState;
bool latchAState;
bool latchBState;

byte burst_bounce_counter;
byte latch_a_bounce_counter;
byte latch_b_bounce_counter;

#endif
