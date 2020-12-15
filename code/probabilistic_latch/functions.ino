void deLatchATrig() {
  latchAState = false;
  if(!(latchAIn)) {latchAJump = true;}
  if(latchAJump) {
    if(latchAIn) {
      latch_a_bounce_counter++;
    } else {
      latch_a_bounce_counter = 0;
    }
    if(unbounce == latch_a_bounce_counter) {
      latchAState = true;
      latchAJump = false;
    }
  }
}

void deBurstTrig() {
  burstState = false;
  if(!(burstIn)) {burstJump = true;}
  if(burstJump) {
    if(burstIn) {
      burst_bounce_counter++;
    } else {
      burst_bounce_counter = 0;
    }
    if(unbounce == burst_bounce_counter) {
      burstState = true;
      burstJump = false;
    }
  }
}

void deLatchBTrig() {
  latchBState = false;
  if(!(latchBIn)) {latchBJump = true;}
  if(latchBJump) {
    if(latchBIn) {
      latch_b_bounce_counter++;
    } else {
      latch_b_bounce_counter = 0;
    }
    if(unbounce == latch_b_bounce_counter) {
      latchBState = true;
      latchBJump = false;
    }
  }
}
