
#include "ServoAbstractions.h"


//////// TCS3200 init////////////////////////////
/////// variable names are from the official TCS3200 documentation.
// digital
#define S0 0
#define S3 1
#define led 2
#define sensorOut 4

// pwm
#define S1 5
#define S2 6

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

void setup() {
  ServoInit();
}

void loop() {
  // put your main code here, to run repeatedly:
  PushItem();
}
