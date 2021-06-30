#pragma once

#define sensorDebug false
#define rgb2hsvDebug true

// Pin Def
const PROGMEM byte TCS_LED = 40;
const PROGMEM byte TCS_S0 = 42;
const PROGMEM byte TCS_S1pwm = 44;
const PROGMEM byte TCS_S2pwm = 46;
const PROGMEM byte TCS_S3 = 48;
const PROGMEM byte TCS_Sout = 50;

enum ColorList {
  black = 0,
  white = 1,
  gray = 128128128,
  red = 255000000,
  green = 000255000,
  blue = 000000255,
  orange = 255165000,
  yellow = 255255000,
  purple = 255000255,

};

enum Color{
  monochrome,
  color
};

enum Degree {
  bright,
  dim,
  dark
};

struct RGB {
  float r;
  float g;
  float b;
};

struct HSV {
  float h;
  int s;
  int v;
};

// Tasks
void TaskColorSensor(void *pvParameters __attribute__((unused)));

// Functions
void Sense();
long rgb2hsv(RGB *rgb);
long colorClassify(HSV *hsv);
