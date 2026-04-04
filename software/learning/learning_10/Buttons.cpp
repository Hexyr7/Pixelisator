// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

//#include "esp32-hal-gpio.h"
#include "Buttons.h"
#include "Context.h"

Buttons::Buttons(int buttonPin, ButtonID ButtonIdentifier) 
  : pin(buttonPin), id(ButtonIdentifier) 
{}

void Buttons::begin() {
  pinMode(pin, INPUT_PULLUP);
}

void Buttons::update(Context& context) {
 
  reading = digitalRead(pin);
  unsigned long now = millis();

  // debounce 
  if (reading != lastReading) {
    lastChangeTime = now;
    lastReading = reading;
  }

  if ((now - lastChangeTime) > debounceTime) {
    
    if (stableState != reading) {
      stableState = reading;

      if (stableState == LOW) {
        Serial.print("klik ");
        Serial.println(now);
        // we can also: Event e{EventType::ButtonPressed, id}
        Event e;
        e.type = EventType::ButtonPressed;
        e.button = id;
        context.pushEvent(e);

        pressStart = now;
        holdSent = false;
      }

      if (stableState == HIGH) {

        Event e;
        e.type = EventType::ButtonReleased;
        e.button = id;

        context.pushEvent(e);
      }
    }
  }

  if (stableState == LOW && !holdSent && (now - pressStart > 500)) {

    if (now - pressStart > 500) {

      Event e;
      e.type = EventType::ButtonHeld;
      e.button = id;

      context.pushEvent(e);

      holdSent = true;
    }
  }

  lastReading = reading;
}
