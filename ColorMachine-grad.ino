
#include "ServoAbstractions.h"
#include <tcs3200.h>

//////// PIN DEFINITIONS ////////////////////////

//////// TCS3200 init////////////////////////////

// (S0, S1, S2, S3, output pin)  //
tcs3200 tcs(0, 5, 6, 1, 4);

////// Stepper motor init //////////////////////
// Digital
#define stepperPin1  8      // IN1 on the ULN2003 driver
// PWM
#define stepperPin2  9      // IN2 on the ULN2003 driver
#define stepperPin3  10     // IN3 on the ULN2003 driver
#define stepperPin4  11     // IN4 on the ULN2003 driver

// Servo motor init
#define servoPin 7

// TODO: Add LCD, Buttons and SDcard.
//////////////////////////////////////////////////

void setup() {
  ServoInit();
}

void loop() {
  // put your main code here, to run repeatedly:
  PushItem();
}
