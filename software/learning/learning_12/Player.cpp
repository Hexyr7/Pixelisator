// Author:  Paweł Bartkiewicz 
// email:   15g.pawel.bart@gmail.com
// github:  Hexyr7
// licence: MIT
#include "Player.h"

Player::Player(Context& ctx, TileMap& tileMap)
  : context(ctx), map(tileMap)
{} 

void Player::update() {

  int playerNewX = playerX;
  int playerNewY = playerY;

  if (context.wasPressed(ButtonID::Up)) {
    playerNewY--;
  }
  if (context.wasPressed(ButtonID::Down)) {
    playerNewY++;
  }
  if (context.wasPressed(ButtonID::Right)) {
    playerNewX++;
  }
  if (context.wasPressed(ButtonID::Left)) {
    playerNewX--;
  }

  if (!map.isWall(playerNewX, playerNewY)) {
    playerX = playerNewX;
    playerY = playerNewY;
  }
}

void Player::draw() {
  auto& gph = context.renderer;

  int screenX = playerX * TILE_SIZE;
  int screenY = playerY * TILE_SIZE;

  gph.fillRect(screenX, screenY, TILE_SIZE, TILE_SIZE, TFT_BLUE);
}

void Player::spawn(TileMap& map) {

  int startX;
  int startY;

  map.findPlayerSpawn(startX, startY);

  playerX = startX;
  playerY = startY;
}