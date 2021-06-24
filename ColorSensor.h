#pragma once

// Pin Def
#define TCS_S0 42
#define TCS_S1pwm 44
#define TCS_S2pwm 46
#define TCS_S3 48
#define TCS_Sout 38
#define TCS_LED 40

struct RGB {
  float r;
  float g;
  float b;
};

struct HSL {
  float h;
  float s;
  float l;
};

// Tasks
void TaskColorSensor(void *pvParameters __attribute__((unused)));

// Functions
void Sense();
struct RGB genRgb(uint16_t *reading_r, uint16_t *reading_g, uint16_t *reading_b, uint16_t *reading_c);
void rgb2hsl(RGB *rgb);
String colorClassify(HSL *hsl);
