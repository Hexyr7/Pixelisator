// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include "Scene.h"
#include "Context.h"

class SceneManager {
  public:
    SceneManager(Scene* blue, Scene* red, Scene* green)
      : blueScene(blue), redScene(red), greenScene(green) {}

    void setScene(Scene* next);
    void update();

  private:
    Scene* current = nullptr;
    Scene* blueScene;
    Scene* redScene;
    Scene* greenScene;
};
