#pragma once

const PROGMEM byte STEPPER_INTERFACE_TYPE = 4;
const PROGMEM byte STEPPER_IN1 = 22;
const PROGMEM byte STEPPER_IN2 = 24;
const PROGMEM byte STEPPER_IN3 = 26;
const PROGMEM byte STEPPER_IN4 = 28;

void StepperInit();
void GoToPlace(int hops);

