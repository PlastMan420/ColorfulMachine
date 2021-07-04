#pragma once

#define sensorDebug false
#define rgb2hsvDebug false
#define colorDeterminationDebug true

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
  gray = 2,
  red = 3,
  green = 4,
  blue = 5,
  orange = 6,
  yellow = 7,
  purple = 8,

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
  int h;
  int s;
  int v;
};

// Tasks
void TaskColorSensor(void *pvParameters __attribute__((unused)));

// Functions
void Sense();
HSV rgb2hsv(RGB *rgb);
long colorClassify(RGB *rgb);
void Output(byte colorIdx);
