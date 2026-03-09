#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
typedef struct Player {
  Vector2 pos;
  float speed;
  int hp;
} Player;
void InitPlayer(Player *p);
void UpdatePlayer(Player *p);
void DrawPlayer(Player *p);
#endif
