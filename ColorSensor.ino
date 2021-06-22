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

  if(debug) Serial.println("Sensor Process Started");
  pinMode(TCS_LED, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    // Readings with LED ON
    digitalWrite(TCS_LED, HIGH);
    vTaskDelay(20);
    // Take X readings.
    sense();

    // Readings with LED ON
    digitalWrite(TCS_LED, LOW);
    vTaskDelay(20);
    // Take X readings.
    sense();

    vTaskSuspend(NULL); //Suspend Own Task
  }
} 


////////// Functions ///////////////////////////////////////////////////
void sense() {
  //float r, g, b;
  RGB rgb;
  HSL hsl;

  uint16_t reading_r, reading_g, reading_b, reading_c;

  reading_r = tcs.colorRead('r');   //reads color value for red
  reading_g = tcs.colorRead('g');   //reads color value for green
  reading_b = tcs.colorRead('b');    //reads color value for blue
  reading_c = tcs.colorRead('c');    //reads color value for white(clear)  

  // converting from raw frequency to the RGB color space.
  rgb.r = (reading_r / reading_c)*256; 
  rgb.g = (reading_g / reading_c)*256; 
  rgb.b = (reading_b / reading_c)*256;
  
  //////////////////////////////////////////////////////////////
  // Convert to HSL
  rgb2hsl(&rgb, &hsl);
  // Logging ///////////////////////////////////////////////////
  if(debug){
    
    // See if we can obtain or "Take" the Serial Semaphore.
    // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {
      log(rgb.r, 'R');
      log(rgb.g, 'G');
      log(rgb.b, 'B');
      log(reading_c, 'C');
    
      Serial.println();

      log(hsl.h, 'H');
      log(hsl.s, 'S');
      log(hsl.l, 'L');
      
      Serial.println();
      // We were able to obtain or "Take" the semaphore and can now access the shared resource.
      xSemaphoreGive( xSerialSemaphore ); // Now free or "Give" the Serial Port for others.
    }

  }
  
  vTaskDelay(30);
}

void log(int val, char c) {
  Serial.print(c);
  Serial.print(" = ");
  Serial.print(val);
  Serial.print("  ");
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
void rgb2hsl(RGB *rgb, HSL *hsl) {
  // the largest guarnteed value is going to be 1.0.
  rgb->r /= 255;
  rgb->g /= 255;
  rgb->b /= 255;
  
  float cMax = 0;
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
  // Luminance
  hsl->l = (cMax - cMin) / 2;

  // Saturation.
  // If Luminance is less or equal to 0.5, then Saturation = (max-min)/(max+min)
  // If Luminance is bigger then 0.5. then Saturation = ( max-min)/(2.0-max-min)
  if(hsl->l <= 0.5)
    hsl->s = (cMax - cMin) / (cMax + cMin);
  else if(hsl->l > 0.5)
    hsl->s = (cMax - cMin) / (2.0 - cMax - cMin);

  // Hue
  // If Red is max, then Hue = (G-B)/(max-min)
  // If Green is max, then Hue = 2.0 + (B-R)/(max-min)
  // If Blue is max, then Hue = 4.0 + (R-G)/(max-min)
  switch(max)
  {
    case 'r':
      hsl->h = (rgb->g - rgb->b) / (cMax - cMin);
      break;
    case 'g':
      hsl->h = 2.0 + (rgb->b - rgb->r) / (cMax - cMin);
      break;
    case 'b':
      hsl->h = 4.0 + (rgb->r - rgb->g) / (cMax - cMin);
      break;
  }
  hsl->h *= 60;
}

String colorClassify(HSL *hsl) {
    if (hsl->l < 0.2)  return "Black";
    if (hsl->l > 0.8)  return "White";

    if (hsl->s < 0.25) return "Gray";
    else if (hsl->h < 30.0)   return "Red";
    else if (hsl->h < 90.0)   return "Yellow";
    else if (hsl->h < 150.0)  return "Green";
    else if (hsl->h < 210.0)  return "Cyan";
    else if (hsl->h < 270.0)  return "Blue";
    else if (hsl->h < 330.0)  return "Magenta";
    return "error";
}