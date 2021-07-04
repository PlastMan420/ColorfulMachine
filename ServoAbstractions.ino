#include <Servo.h>
#include <StreamUtils.h>
#include "ServoAbstractions.h"

Servo servo;

void ServoInit()
{
  servo.attach(SERVO_PIN);
  servo.write(90);
  delay(1000);
}

void ServoSleep() {
  servo.detach();
}

void PushItem(bool eject = false) {
  if (eject) servo.write(0);
  else servo.write(180);
  delay(1000);
  servo.write(90);
}
