#include <SPI.h>
#include <SD.h>
#include <ArduinoJson.h>
#include "JsonAbstractions.h"

enum ColorSet {
  RED,
  YELLOW,
  BLUE,
  GREEN,
  ORANGE,
  PURPLE,

};

const byte staticJsonSize = 32;
//const char *filename = "/config.txt";

void SdCardInit() {
  if(debug) Serial.print("Initializing SD card...");
  
  SD.begin(CS);

}

void UpdateConfig(struct Config *config, const char *filename) {
  // drop parameter translates into accelestepper "location".
  // color is a HEX representation of RGB.
  File file = SD.open(filename);

  StaticJsonDocument<staticJsonSize> conf;
  // Deserialize the JSON document
  DeserializationError error = deserializeJson(conf, file);
  if (error)
    Serial.println(F("Failed to read file."));

  conf["color"] = config->color;
  conf["drop"] = config->drop;

  serializeJson(conf, file);

  file.close();
}

