// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#pragma once 
#include "Context.h"

class TileMap {
public:
  TileMap(Context& ctx);

  //nazwa do zmiany
  void draw();
  bool isWall(int x, int y);
  void findPlayerSpawn(int& startX, int& startY);
  void findGoal(int& goalX, int& goalY);

private:
  Context& context;

  int startX;
  int startY;
  int goalX;
  int goalY;

  static const int WIDTH = 15;
  static const int HEIGHT = 10;
  static const int TILE_SIZE = 32;

  uint8_t themap[10][15] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,3,0,0,0,0,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,0,1,0,1,1,1,0,1,0,1},
    {1,0,0,0,1,0,0,0,0,1,0,0,1,0,1},
    {1,1,1,0,1,1,0,1,0,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,0,1,1,1,1,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
    {1,0,1,1,0,1,1,1,1,1,0,1,1,4,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
  };

uint8_t themap2[10][15] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,3,1,0,0,1,0,0,1},
    {1,0,1,1,0,1,1,0,1,0,1,1,0,1,1},
    {1,0,1,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,0,1,0,1,0,0,1,1,0,0,1,1,0,1},
    {1,0,0,0,1,0,1,0,0,1,0,0,1,0,1},
    {1,1,1,0,1,0,1,1,0,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,0,0,0,1,0,1},
    {1,4,1,1,1,1,0,1,1,1,1,0,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
  };
};
