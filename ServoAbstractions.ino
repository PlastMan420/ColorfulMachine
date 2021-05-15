#include <Servo.h>

Servo servo;

void ServoInit()
{
  servo.attach(servoPin);
  servo.write(0);
  delay(1000);
}

void PushItem() {
  servo.write(60);
  delay(1000);
  servo.write(0);
  delay(600);

}
