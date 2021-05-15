#include <AccelStepper.h>

AccelStepper carousel(4, stepperPin1, stepperPin2, stepperPin3, stepperPin4);

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
