#include <tcs3200.h>
#include <Arduino_FreeRTOS.h>
#include "StepperAbstractions.h"
#include "ServoAbstractions.h"

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
  float r, g, b;
  uint16_t reading_r, reading_g, reading_b, reading_c;

  reading_r = tcs.colorRead('r');   //reads color value for red
  reading_g = tcs.colorRead('g');   //reads color value for green
  reading_b = tcs.colorRead('b');    //reads color value for blue
  reading_c = tcs.colorRead('c');    //reads color value for white(clear)  

  // converting from raw frequency to the RGB color space.
  r = (reading_r / reading_c)*256; 
  g = (reading_g / reading_c)*256; 
  b = (reading_b / reading_c)*256;
  
  //////////////////////////////////////////////////////////////
  
  // Logging ///////////////////////////////////////////////////
  if(debug){
    
    // See if we can obtain or "Take" the Serial Semaphore.
    // If the semaphore is not available, wait 5 ticks of the Scheduler to see if it becomes free.
    if ( xSemaphoreTake( xSerialSemaphore, ( TickType_t ) 5 ) == pdTRUE )
    {
      log(r, 'R');
      log(g, 'G');
      log(b, 'B');
      log(reading_c, 'C');
    
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