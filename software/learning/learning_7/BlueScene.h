// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once
#include <Arduino.h>
#include "Scene.h"

class BlueScene : public Scene {
public:
  BlueScene(Context& ctx) : Scene(ctx) {}
  
  void setBlinkScene(Scene* scene);
  void onEnter() override;
  void onExit() override;
  void update() override;
private: 
  Scene* blinkScene = nullptr;
};



