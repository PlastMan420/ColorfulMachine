#include <SPI.h>
#include <SD.h>
#include <ArduinoJson.h>
#include <StreamUtils.h>
#include "JsonAbstractions.h"

//const char *filename = "/config.txt";

const PROGMEM byte TABLE_ADDRESS = 0;
const PROGMEM byte TABLE_SIZE = 150;
const PROGMEM byte STATIC_JSON_SIZE = 32;

void SdCardInit() {
  #if DEBUG == true
    Serial.print(F("Initializing SD card..."));
  #endif
  SD.begin(CS);

}

void ReadConfig() {
  
}

#if USE_EEPROM == true

void UpdateConfigEeprom(Config *p_config) {
  // drop parameter translates into accelestepper "location".
  // color is a HEX representation of RGB.

  StaticJsonDocument<STATIC_JSON_SIZE> conf;

  EepromStream eepromStream(TABLE_ADDRESS, TABLE_SIZE);
  deserializeJson(conf, eepromStream);

  conf[p_config->drop] = p_config->color;

  serializeJson(conf, eepromStream);

}

#else

void UpdateConfig(Config p_config, const char *p_filename) {
  // drop parameter translates into accelestepper "location".
  // color is a HEX representation of RGB.

  StaticJsonDocument<STATIC_JSON_SIZE> conf;

  File file = SD.open(p_filename);
  deserializeJson(conf, file);

  conf[p_config->drop] = p_config->color;

  serializeJson(conf, file);

  file.close();

}

#endif

void UpdateLog() {
  
}
