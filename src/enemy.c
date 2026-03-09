#include "enemy.h"
void InitEnemies(Enemy enemies[]) {
  for (int i = 0; i < MAX_ENEMIES; i++) {
    enemies[i].pos.x = GetRandomValue(0, 600);
    enemies[i].pos.y = GetRandomValue(-400, -50);
    enemies[i].speed = GetRandomValue(2, 5);
    enemies[i].active = true;
  }
}
void UpdateEnemies(Enemy enemies[], Vector2 playerpos) {
  float lateralspeed = 1.5f;
  for (int i = 0; i < MAX_ENEMIES; i++) {
    if (enemies[i].active) {
      enemies[i].pos.y += enemies[i].speed;
      if (enemies[i].pos.x < playerpos.x) {
        enemies[i].pos.x += lateralspeed;
      } else if (enemies[i].pos.x > playerpos.x) {
        enemies[i].pos.x -= lateralspeed;
      }
      if (enemies[i].pos.y > 800) {
        enemies[i].pos.y = -50;
        enemies[i].pos.x = GetRandomValue(0, 600);
      }
    }
  }
}
void DrawEnemies(Enemy enemies[]) {
  for (int i = 0; i < MAX_ENEMIES; i++) {
    if (enemies[i].active) {
      DrawRectangle(enemies[i].pos.x - 20, enemies[i].pos.y - 20, 40, 40, RED);
    }
  }
}
