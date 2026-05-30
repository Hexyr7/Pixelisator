// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT

#include "TileMap.h"

TileMap::TileMap(Context& ctx)
  : context(ctx)
{}

void TileMap::draw() {
  auto& gph = context.renderer;

  for (int y = 0; y < HEIGHT; y++ ) {
    for (int x = 0; x < WIDTH; x++) {

      int tile = themap2[y][x];

      int screenX = x * TILE_SIZE;
      int screenY = y * TILE_SIZE;

      if (tile == 1) {
        gph.fillRect(screenX, screenY, TILE_SIZE, TILE_SIZE, TFT_YELLOW);
      } else if (tile == 3) { 
        gph.fillRect(screenX, screenY, TILE_SIZE, TILE_SIZE, TFT_RED);
      } else if (tile == 4) {
        gph.fillRect(screenX, screenY, TILE_SIZE, TILE_SIZE, TFT_GREEN);
      } else {
        gph.fillRect(screenX, screenY, TILE_SIZE, TILE_SIZE, TFT_BLACK);  
      }
    }
  }
}

bool TileMap::isWall(int x, int y) {
  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
    return true; //player out of map
  } 
  return themap2[y][x] == 1;
}

void TileMap::findPlayerSpawn(int& startX, int& startY) {

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {

      if (themap2[y][x] == 3) {

        startX = x;
        startY = y;
        return;
      }
    }
  }
}

void TileMap::findGoal(int& goalX, int& goalY) {

  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {

      if (themap2[y][x] == 4) {

        goalX = x;
        goalY = y;
        return;
      }
    }
  }
}