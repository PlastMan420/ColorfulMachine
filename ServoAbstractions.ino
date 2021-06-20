// Servo Motor Abstractions. specific to this system's design.

#include <Servo.h>
#include "ServoAbstractions.h"

Servo servo;

void ServoInit()
{
  servo.attach(SERVO_PIN);
  servo.write(0);
  delay(1000);
}

void PushItem() {
  servo.write(60);
  delay(1000);
  servo.write(0);
  delay(600);

}
