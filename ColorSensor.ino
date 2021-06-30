#include <tcs3200.h>
#include <Arduino_FreeRTOS.h>
#include "StepperAbstractions.h"
#include "ServoAbstractions.h"
#include "ColorSensor.h"

// Init
// (S0, S1, S2, S3, output pin)  //
tcs3200 tcs(TCS_S0, TCS_S1pwm, TCS_S2pwm, TCS_S3, TCS_Sout);
    
// Tasks ////////////////////////////////////////////////////////////////
void TaskColorSensor(void *pvParameters __attribute__((unused))) {

  
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


    vTaskSuspend(NULL);  //Suspend Own Task
  }                      // Task Loop
}


////////// Functions ///////////////////////////////////////////////////
void sense() {
 
  RGB rgb;
  uint32_t sum = 0;

   // sub-scope to free memory later
  {
    uint16_t reading_r = tcs.colorRead('r', 20);  //reads color value for red
    uint16_t reading_g = tcs.colorRead('g', 20);  //reads color value for green
    uint16_t reading_b = tcs.colorRead('b', 20);  //reads color value for blue
    uint16_t reading_c = tcs.colorRead('c', 20);  //reads color value for white(clear)
    sum = reading_c;

    // converting from raw frequency to the RGB color space.
    rgb.r = (float)reading_r / (float)sum;
    rgb.g = (float)reading_g / (float)sum;
    rgb.b = (float)reading_b / (float)sum;
  }
  
    // Debugging ///////////////////////////////////////////////////
  #if DEBUG == true && sensorDebug == true
    rgb.r *= 256.0;
    rgb.g *= 256.0;
    rgb.b *= 256.0;

    if (xSemaphoreTake(xSerialSemaphore, 10) == pdTRUE) {
        Serial.println(rgb.r);
        Serial.println(rgb.g);
        Serial.println(rgb.b);

      xSemaphoreGive(xSerialSemaphore);
    }
  #endif  // debug

  long color = rgb2hsv(&rgb);

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
long rgb2hsv(RGB *rgb) {

  int r = rgb->r * 100;
  int g = rgb->g * 100;
  int b = rgb->b * 100;
  


  int cmax = 1;
  int cmin = 100;

  cmin = min(cmin, r);
  cmin = min(cmin, g);
  cmin = min(cmin, b);

  cmax = max(cmax, r);
  cmax = max(cmax, g);
  cmax = max(cmax, b);

  // delta will range from 1 to 100.
  int delta = cmax - cmin;

  HSV hsv;

  // Value
  hsv.v = cmax;

  // Saturation
  if (cmax < 2)
    hsv.s = 0;
  else
    hsv.s = (delta / cmax)*100;

  // Hue
  // If Red is max, then Hue = (G-B)/(max-min) % 6
  // If Green is max, then Hue = 2.0 + (B-R)/(max-min)
  // If Blue is max, then Hue = 4.0 + (R-G)/(max-min)
  if (delta == 0)
    hsv.h = 0;
  else {

    if (cmax == r)
        hsv.h = fmod((60 * ((g - b) / delta) + 360), 360);

    // if cmax equal g then compute h
    else if (cmax == g)
        hsv.h = fmod((60 * ((b - r) / delta) + 120), 360);

    // if cmax equal b then compute h
    else if (cmax == b)
        hsv.h = fmod((60 * ((r - g) / delta) + 240), 360);
  }


    // Debugging ///////////////////////////////////////////////////
  #if DEBUG == true && rgb2hsvDebug == true
    if (xSemaphoreTake(xSerialSemaphore, 10) == pdTRUE) {
        Serial.println(hsv.h);
        Serial.println(hsv.s);
        Serial.println(hsv.v);
        Serial.println();
      xSemaphoreGive(xSerialSemaphore);
    }
  #endif  // debug

  return colorClassify(&hsv);
}

long colorClassify(HSV *hsv) {

  enum Color _color;
  enum Degree _degree;
  enum ColorList _cList;

  if(hsv->s < 25)
    _color = monochrome;
  else
    _color = color;

  if(hsv->v < 30)
    _degree = dark;

  else if (hsv->v > 75)
    _degree = bright;

  if (_color == monochrome) 
  {
    switch(_degree) {
      case bright: 
        _cList = white;
      break;
      case dark: 
        _cList = black;
      break;
      case dim:
        _cList = gray;
      break;
    }

  }

  else {

    if (hsv->h >= 0 && hsv->h < 40 || hsv->h >= 310 && hsv->h <= 360)
    {
      _cList = red;
    }
    else if (hsv->h >= 45 && hsv->h < 55)
      _cList = yellow;
    else if (hsv->h >= 55 && hsv->h < 150)
      _cList = green;
    else if (hsv->h >= 150 && hsv->h < 270)
      _cList = blue;
    else if (hsv->h >+ 270 && hsv->h < 310)
      _cList = purple;

  }


  return _cList;
}
