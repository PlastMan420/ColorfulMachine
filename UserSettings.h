#pragma once

struct Config {
  byte drop;
  int color;
};

void UpdateConfigTable(Config *p_conf);
