// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once
#include <Arduino.h>
#include "Event.h"
//#include "Context.h"
struct Context; // <-- forward declaration

class Buttons {
public:
  Buttons(int buttonPin, ButtonID id);

  void begin();
  void update(Context& context);

private:
  int pin;
  ButtonID id;
  unsigned long pressStart = 0;
  bool holdSent = false;

  bool reading = false;
  bool lastReading = HIGH;
  bool stableState = HIGH;
  const unsigned long debounceTime = 30;
  unsigned long lastChangeTime = 0;
};