// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once
#include "Buttons.h"
#include "TFT_eSPI.h"

struct Context {
  TFT_eSPI& tft;
  Buttons& buttons;

  Context(Buttons& btn, TFT_eSPI& display) : buttons(btn), tft(display) {}
};
