#pragma once
#include "UserSettings.h"

#define USE_EEPROM true

const PROGMEM byte CS = 53;
//const PROGMEM uint8_t MOSI = 51;
const PROGMEM byte CLK = 52;
//const PROGMEM uint8_t MISO = 50;

void SdCardInit();

#if USE_EEPROM == true
void UpdateConfigJsonEeprom(Config *p_config);
#else
void UpdateConfigJson(Config *p_config, const char *p_filename);
#endif