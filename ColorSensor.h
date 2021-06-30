#pragma once

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

struct HSL {
  int h;
  byte s;
  byte v;
};

// Tasks
void TaskColorSensor(void *pvParameters __attribute__((unused)));

// Functions
void Sense();
struct RGB genRgb(uint16_t *reading_r, uint16_t *reading_g, uint16_t *reading_b, uint16_t *reading_c);
String rgb2hsv(RGB *rgb);
String colorClassify(HSL *hsl);
