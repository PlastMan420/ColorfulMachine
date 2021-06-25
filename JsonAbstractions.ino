#include <SPI.h>
#include <SD.h>
#include <ArduinoJson.h>
#include "JsonAbstractions.h"

//const char *filename = "/config.txt";

void SdCardInit() {
  #if DEBUG == true
    Serial.print("Initializing SD card...");
  #endif
  SD.begin(CS);

}

void ReadConfig() {
  
}

void UpdateConfig(struct Config *config, const char *filename) {
  // drop parameter translates into accelestepper "location".
  // color is a HEX representation of RGB.
  const byte staticJsonSize = 32;

  File file = SD.open(filename);

  StaticJsonDocument<staticJsonSize> conf;
  // Deserialize the JSON document
  DeserializationError error = deserializeJson(conf, file);
  if (error)
    {
      Serial.println(F("Failed to read file."));
      return;
    }

  conf[config->drop] = config->color;

  serializeJson(conf, file);

  file.close();
}

void UpdateLog() {
  
}
