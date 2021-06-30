#include <tcs3200.h>
#include <Arduino_FreeRTOS.h>
#include "StepperAbstractions.h"
#include "ServoAbstractions.h"
#include "ColorSensor.h"
//#include "helpers.h"

// Init
// (S0, S1, S2, S3, output pin)  //
tcs3200 tcs(TCS_S0, TCS_S1pwm, TCS_S2pwm, TCS_S3, TCS_Sout);

// Tasks ////////////////////////////////////////////////////////////////
void TaskColorSensor(void *pvParameters __attribute__((unused))) {
//Serial.println("Resuming color sensor task");
#if DEBUG == true
  Serial.println("Sensor Process Started");
#endif

  pinMode(TCS_LED, OUTPUT);

  for (;;)  // A Task shall never return or exit.
  {

    // Readings with LED ON
    digitalWrite(TCS_LED, HIGH);
    vTaskDelay(40);
    // Take X readings.
    sense();

    // Readings with LED ON
    digitalWrite(TCS_LED, LOW);
    vTaskDelay(40);
    // Take X readings.
    sense();

    vTaskDelay(40);


    vTaskSuspend(NULL);  //Suspend Own Task
  }                      // Task Loop
}


////////// Functions ///////////////////////////////////////////////////
void sense() {
 
   RGB rgb;
   // sub-scope to free memory later
  {
    uint16_t reading_r = tcs.colorRead('r');  //reads color value for red
    uint16_t reading_g = tcs.colorRead('g');  //reads color value for green
    uint16_t reading_b = tcs.colorRead('b');  //reads color value for blue
    uint16_t reading_c = tcs.colorRead('c');  //reads color value for white(clear)

    // converting from raw frequency to the RGB color space.
    rgb.r = reading_r;
    rgb.g = reading_g;
    rgb.b = reading_b;

    rgb.r /= reading_c;
    rgb.g /= reading_c;
    rgb.b /= reading_c;
  }
  rgb.r *= 256.0;
  rgb.g *= 256.0;
  rgb.b *= 256.0;

  String color = rgb2hsv(&rgb);
}

void machine() {
  // TODO
  // This is the color sorting Process
}

/*
* This injects an item into the system using the servo motor(s). from the cache by the color sensor.
*/
void inject() {
}

// Convert RGB to HSL
String rgb2hsv(RGB *rgb) {

  rgb->r /= 255.0;
  rgb->g /= 255.0;
  rgb->b /= 255.0;

  byte r = byte(rgb->r * 100.0);
  byte g = byte(rgb->g * 100.0);
  byte b = byte(rgb->b * 100.0);

  // float cMax = 0.1;
  // float cMin = 1.0;

  byte cMax = 100; 
  byte cMin = 1;

  char max = '0';

  cMin = min(cMin, r);
  cMin = min(cMin, g);
  cMin = min(cMin, b);

  if (r > b && r > g) {
    max = 'r';
    cMax = r;
  } else if (b > r && b > g) {
    max = 'b';
    cMax = b;
  } else if (g > b && g > r) {
    max = 'g';
    cMax = g;
  }

  byte delta = cMax - cMin;

  HSL hsl;

  // Value
  hsl.v = cMax;

  // Saturation
  if (cMax == 0 || cMax == 1)
    hsl.s = 0;
  else
    hsl.s = (delta / cMax) * 100;

  // Hue
  // If Red is max, then Hue = (G-B)/(max-min)
  // If Green is max, then Hue = 2.0 + (B-R)/(max-min)
  // If Blue is max, then Hue = 4.0 + (R-G)/(max-min)
  if (delta == 0)
    hsl.h = 0;
  else {
    switch (max) {
      case 'r':
        hsl.h = fmod(((g - b) / delta), 6.0);
        break;
      case 'g':
        hsl.h = 2 + ((b - r) / delta);
        break;
      case 'b':
        hsl.h = 4 + ((r - g) / delta);
        break;
    }
  }

  hsl.h *= 60;

  if ((g - b) < 0)
    hsl.h += 360;

  String color = colorClassify(&hsl);

  // Debugging ///////////////////////////////////////////////////
  #if DEBUG == true
    if (xSemaphoreTake(xSerialSemaphore, 10) == pdTRUE) {
        Serial.println(color);
      xSemaphoreGive(xSerialSemaphore);
    }
  #endif  // debug

  return color;
}

String colorClassify(HSL *hsl) {

  // if(hsl->h < 5)
  // if (hsl->v < 20.0) return "black";
  // else if (hsl->v > 80)
  //   return "white";
  // else
  //   return "gray";
  enum Color _color;
  enum Degree _degree;

  if(hsl->s < 25)
    _color = monochrome;
  else
    _color = color;

  if(hsl->v < 30)
    _degree = dark;

  else if (hsl->v > 75)
    _degree = bright;

  if (_color == monochrome) 
  {
    if (_degree == bright) return "white";
    else if (_degree == dark) return "black";
    else if(_degree == dim) return "gray";
  }
  else {

    if (hsl->h >= 0 && hsl->h < 40.0)
      return "orange";
    else if (hsl->h > 50.0 && hsl->h < 60.0)
      return "yellow";
    else if (hsl->h > 80.0 && hsl->h < 150.0)
      return "green";
    else if (hsl->h < 270.0)
      return "Blue";
    else if (hsl->h < 330.0)
      return "pruple";

  }


  return "error";
}
