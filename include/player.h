#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"
#define MAX_BULLETS 10

typedef struct {
  Vector2 pos;
  float speed;
  bool active;
} Bullet;

typedef struct Player {
  Vector2 pos;
  float speed;
  int hp;
  Bullet bullets[MAX_BULLETS];
} Player;
void InitPlayer(Player *p);
void UpdatePlayer(Player *p);
void DrawPlayer(Player *p);
#endif
