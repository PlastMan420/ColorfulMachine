#include <AccelStepper.h>
#include "StepperAbstractions.h"

// choose '4' in the first parameter for ULN2003AN controlling or similar.
// IN1, pwmIN2, pwmIN3, pwmIN4.
AccelStepper carousel(4, STEPPER_IN1, STEPPER_IN2, STEPPER_IN3, STEPPER_IN4);

void StepperInit() {
  carousel.setMaxSpeed(1000.0);
  carousel.setSpeed(500.0);
}

void GoToPlace() {
  // .runToNewPosition() blocks the execusion thread until its finished.
  carousel.runToNewPosition(0);
  carousel.runToNewPosition(500);
  carousel.runToNewPosition(100);
  carousel.runToNewPosition(120);
}
