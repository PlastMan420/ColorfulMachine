#include <EEPROM.h>
#include "UserSettings.h"

void UpdateConfigTable(Config *p_conf) {
  EEPROM.write(p_conf->drop, p_conf->color);

}