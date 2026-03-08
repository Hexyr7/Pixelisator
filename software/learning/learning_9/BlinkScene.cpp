#include "Event.h"
// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "BlinkScene.h"
//#include <TFT_eSPI.h>
//#include "Buttons.h"

//extern TFT_eSPI tft;
//extern Buttons buttons;

void BlinkScene::setBlueScene(Scene* scene) {
  blueScene = scene;
}

void BlinkScene::onEnter() {
  Serial.println("BlinkScene onEnter()");
  context.tft.fillScreen(TFT_BLACK);
}

void BlinkScene::onExit() {
  Serial.println("BlinkScene onExit()");
}

void BlinkScene::update() {

  if (millis() - lastToggle > 1000) {
    lastToggle = millis();
    state = !state;

    context.tft.fillScreen (state ? TFT_WHITE : TFT_BLACK); //if state then white else black
  }

  if (context.wasPressed(ButtonID::A)) {

    Serial.println("Go to BlueScene");
    nextScene = blueScene;
  }
}
