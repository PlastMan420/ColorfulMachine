#pragma once

#define STEPPER_MODEL A4988

#if STEPPER_MODEL == uln2003
// Stepper Motor (28BYJ-48) with ULN2003
const PROGMEM byte STEPPER_INTERFACE_TYPE = 4;
const PROGMEM byte STEPPER_IN1 = 22;
const PROGMEM byte STEPPER_IN2 = 24;
const PROGMEM byte STEPPER_IN3 = 26;
const PROGMEM byte STEPPER_IN4 = 28;

#elif STEPPER_MODEL == A4988
// A4988 with a shield.
const PROGMEM byte STEPPER_INTERFACE_TYPE = 1;
const PROGMEM byte STEPPIN = 22; 
const PROGMEM byte DIRPIN = 24; 
#endif

void StepperInit();
void StepperInitA4988();
void GoToPlace(int hops);

