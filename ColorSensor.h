#ifndef COLORSENSOR_H
  #define COLORSENSOR_H
  
  // Pin Def
  #define TCS_S0 42
  #define TCS_S1pwm 44
  #define TCS_S2pwm 46
  #define TCS_S3 48
  #define TCS_Sout 52
  #define TCS_LED 40

  // Functions
  void Sense();
  
  // Tasks
  void TaskColorSensor(void *pvParameters __attribute__((unused)));
#endif