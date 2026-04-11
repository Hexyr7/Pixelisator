// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once
#include <TFT_eSPI.h>

class Renderer { 
public:

  Renderer(TFT_eSPI& display);

  void clear(uint16_t color);
  void drawPixel(int x, int y, uint16_t color);
  void drawRect(int x, int y, int w, int h, uint16_t color);
  void fillRect(int x, int y, int w, int h, uint16_t color);

private:
  TFT_eSPI& tft;
};