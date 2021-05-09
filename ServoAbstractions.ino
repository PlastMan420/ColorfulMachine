#include <Servo.h>

Servo servo;

void ServoInit()
{
  servo.attach(servoPin);
  servo.write(0);

}

void PushItem() {
  servo.write(60);
  delay(500);
  servo.write(0);
  delay(400);

}
