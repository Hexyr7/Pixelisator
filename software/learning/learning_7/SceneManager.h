// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include "Scene.h"
#include "Context.h"

class SceneManager {
  public:
    SceneManager(Scene* blink, Scene* blue)
      : blinkScene(blink), blueScene(blue) {}

    void setScene(Scene* next);
    void update();

  private:
    Scene* current = nullptr;
    Scene* blinkScene;
    Scene* blueScene;
};
