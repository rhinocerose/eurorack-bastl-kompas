//Clock and Reset input detection
void deReset() {
  resetState = false;
  if(!(resetIn)) {resetJump = true;}
  if(resetJump) {
    if(resetIn) {
      reset_bounce_counter++;
    } else {
      reset_bounce_counter = 0;
    }
    if(unbounce == reset_bounce_counter) {
      resetState = true;
      resetJump = false;
    }
  }
}


void deClock() {
  clockState = false;
  if(!(clockIn)) {clockJump = true;}
  if(clockJump) {
    if(clockIn) {
      clock_bounce_counter++;
    } else {
      clock_bounce_counter = 0;
    }
    if(unbounce == clock_bounce_counter) {
      clockState = true;
      clockJump = false;
    }
  }
}
