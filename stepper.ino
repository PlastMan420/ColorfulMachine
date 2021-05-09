#include <AccelStepper.h>

AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

public void StepperInit() {
  stepper.setMaxSpeed(1000);
  stepper.setSpeed(50);
}
