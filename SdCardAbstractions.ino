#include <SPI.h>
#include <SD.h>
#include <ArduinoJson.h>
#include "SdCardAbstractions.h"

struct Config {
  uint32_t color;
  long drop;
};

Config config;

void SdCardInit() {
  if(debug) Serial.print("Initializing SD card...");
  
  SD.begin(CS);

}

void UpdateConfig(uint32_t *color, long *drop) {
  // drop parameter translates into accelestepper "location".
  // color is a HEX representation of RGB.
  config.color = *color;
  config.drop = *drop;
}