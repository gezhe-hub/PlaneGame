#ifndef ENEMY_H
#define ENEMY_H
#include "raylib.h"
#define MAX_ENEMIES 8
typedef struct {
  Vector2 pos;
  float speed;
  bool active;
} Enemy;
void InitEnemies(Enemy enemies[]);
void UpdateEnemies(Enemy enemies[], Vector2 playerpos);
void DrawEnemies(Enemy enemies[]);
#endif
