#pragma once

#define CS 53
#define MOSI 51
#define CLK 52
#define MISO 50

struct Config {
  long color;
  long drop;
};

void SdCardInit();
void UpdateConfig(struct Config *config, const char *filename);
