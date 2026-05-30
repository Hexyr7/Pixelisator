// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "Renderer.h"

Renderer::Renderer(TFT_eSPI& display)
  : tft(display)
{}

void Renderer::clear(uint16_t color){
  tft.fillScreen(color);
}
void Renderer::drawPixel(int x, int y, uint16_t color){
  tft.drawPixel(x, y, color);
}
void Renderer::drawRect(int x, int y, int w, int h, uint16_t color){
  tft.drawRect(x, y, w, h, color);
}
void Renderer::fillRect(int x, int y, int w, int h, uint16_t color){
  tft.fillRect(x, y, w, h, color);
}