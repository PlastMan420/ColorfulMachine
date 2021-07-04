#include <AccelStepper.h>
#include <StreamUtils.h>
#include "StepperAbstractions.h"

const PROGMEM int STEPS = 850;
int currentPosition = 0;
// choose '4' in the first parameter for ULN2003AN controlling or similar.
// IN1, pwmIN2, pwmIN3, pwmIN4.
AccelStepper carousel(STEPPER_INTERFACE_TYPE, STEPPER_IN1, STEPPER_IN2, STEPPER_IN3, STEPPER_IN4);

void StepperInit() {
  carousel.setMaxSpeed(2000.0);
  carousel.setAcceleration(2000.0);
}

void GoToPlace(int hops) {
  currentPosition = STEPS * hops;
  
  carousel.runToNewPosition(currentPosition);
  
}

// TODO
// Stream stepper state into a file on sdcard