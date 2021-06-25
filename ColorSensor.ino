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
  //Serial.println("Resuming color sensor task");
  #if DEBUG == true
    Serial.println("Sensor Process Started");
  #endif

  pinMode(TCS_LED, OUTPUT);

  for (;;) // A Task shall never return or exit.
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


    vTaskSuspend(NULL); //Suspend Own Task
  } // Task Loop

} 


////////// Functions ///////////////////////////////////////////////////
void sense() {

  uint16_t reading_r = tcs.colorRead('r');   //reads color value for red
  uint16_t reading_g = tcs.colorRead('g');   //reads color value for green
  uint16_t reading_b = tcs.colorRead('b');    //reads color value for blue
  uint16_t reading_c = tcs.colorRead('c');    //reads color value for white(clear)  

  RGB rgb;
  // converting from raw frequency to the RGB color space.
  rgb.r = (reading_r);
  rgb.g = (reading_g);
  rgb.b = (reading_b);
  
  rgb.r /= reading_c;
  rgb.g /= reading_c;
  rgb.b /= reading_c;

  rgb.r *= 256;
  rgb.g *= 256;
  rgb.b *= 256;

  //rgb2hsl(&rgb);  

    // Debugging ///////////////////////////////////////////////////
  #if DEBUG == true
  if (xSemaphoreTake(xSerialSemaphore, 10) == pdTRUE)
  {
    log(&rgb.r, 'R');
    log(&rgb.g, 'G');
    log(&rgb.b, 'B');
    //log(&reading_c, 'C');
    Serial.println();

    xSemaphoreGive(xSerialSemaphore);
  }
  #endif // debug

}

void machine() {
  // TODO
  // This is the color sorting Process
}

/*
* This injects an item into the system using the servo motor(s). from the cache by the color sensor.
*/
void inject()
{
  
}

// Convert RGB to HSL
void rgb2hsl(RGB *rgb) {

  HSL hsl;

  rgb->r /= 255.0;
  rgb->g /= 255.0;
  rgb->b /= 255.0;
  
  float cMax = 0.1;
  float cMin = 1.0;
  char max = '0';

  cMin = min(cMin, rgb->r);
  cMin = min(cMin, rgb->g);
  cMin = min(cMin, rgb->b);

  if(rgb->r > rgb->b && rgb->r > rgb->g)
  {
    max = 'r';
    cMax = rgb->r;
  }
  else if(rgb->b > rgb->r && rgb->b > rgb->g)
  {
    max = 'b';
    cMax = rgb->b;
  }  
  else if(rgb->g > rgb->b && rgb->g > rgb->r)
  {
    max = 'g';
    cMax = rgb->g;
  }

  float sumMaxMin = cMax + cMin;
  float subMaxMin = cMax - cMin;
  

    // Luminance
  hsl.l = subMaxMin / 2.0;

  // Saturation.
  // If Luminance is less or equal to 0.5, then Saturation = (max-min)/(max+min)
  // If Luminance is bigger then 0.5. then Saturation = ( max-min)/(2.0-max-min)
  if(hsl.l <= 0.5)
    hsl.s = subMaxMin / sumMaxMin;
  else if(hsl.l > 0.5)
    hsl.s = subMaxMin / (2.0 - subMaxMin);

  // Hue
  // If Red is max, then Hue = (G-B)/(max-min)
  // If Green is max, then Hue = 2.0 + (B-R)/(max-min)
  // If Blue is max, then Hue = 4.0 + (R-G)/(max-min)
  switch(max)
  {
    case 'r':
      hsl.h = (rgb->g - rgb->b) / subMaxMin;
      break;
    case 'g':
      hsl.h = 2.0 + (rgb->b - rgb->r) / subMaxMin;
      break;
    case 'b':
      hsl.h = 4.0 + (rgb->r - rgb->g) / subMaxMin;
      break;
  }

  hsl.h *= 60.0;
 
  hsl.color = colorClassify(&hsl);
  Serial.println(hsl.color);

}

String colorClassify(HSL *hsl) {

  if (hsl->l < 0.2)  return "black";
  else if (hsl->l > 0.8)  return "white";

  if (hsl->s < 0.25) return "gray";

  if (hsl->h < 20.0)   return "red";
  else if (hsl->h > 20.0 && hsl->h < 40.0)  return "orange";
  else if (hsl->h > 50.0 && hsl->h < 60.0)  return "yellow";
  else if (hsl->h > 80.0 && hsl->h < 150.0)  return "green";
  else if (hsl->h > 170.0 && hsl->h < 190.0)  return "Orange";
  else if (hsl->h < 270.0)  return "Blue";
  else if (hsl->h < 330.0)  return "pruple";

  return "error";
}

#if DEBUG == true
void log(float *val, char c) {

    Serial.print(c);
    Serial.print(": ");
    Serial.print(*val);
    Serial.print("  ");

}
#endif
