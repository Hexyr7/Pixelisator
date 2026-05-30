// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include "Context.h"
#include "TileMap.h"

class Player {
public:
  Player(Context& ctx, TileMap& tileMap);

  void update();
  void draw();
  void spawn(TileMap& map); 


private:
  Context& context; 
  TileMap& map;

  int playerX;
  int playerY;

  static const int TILE_SIZE = 32;

};