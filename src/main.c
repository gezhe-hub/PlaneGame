#include "enemy.h"
#include "player.h"
#include "raylib.h"
int main() {
  const int screenWidth = 600;
  const int screenHeight = 800;
  InitWindow(screenWidth, screenHeight, "Plane Game - v0.1");
  SetTargetFPS(60);
  Player hero;
  InitPlayer(&hero);
  Enemy enemies[MAX_ENEMIES];
  InitEnemies(enemies);
  int score = 0;
  while (!WindowShouldClose()) {
    UpdatePlayer(&hero);
    UpdateEnemies(enemies, hero.pos);
    for (int i = 0; i < MAX_BULLETS; i++) {
      if (hero.bullets[i].active) {
        for (int j = 0; j < MAX_ENEMIES; j++) {
          if (enemies[j].active) {
            Rectangle bulletRec = {hero.bullets[i].pos.x - 5,
                                   hero.bullets[i].pos.y - 5, 10, 10};
            Rectangle enemyRec = {enemies[j].pos.x - 20, enemies[j].pos.y - 20,
                                  40, 40};
            if (CheckCollisionRecs(bulletRec, enemyRec)) {
              hero.bullets[i].active = false;
              enemies[i].active = false;
              enemies[j].pos.y = -50;
              enemies[j].pos.x = GetRandomValue(0, screenWidth);
              enemies[j].active = true;
              score += 100;
            }
          }
        }
      }
    }
    for (int j = 0; j < MAX_ENEMIES; j++) {
      if (enemies[j].active) {
        Rectangle playerRec = {hero.pos.x - 20, hero.pos.y - 20, 40, 40};
        Rectangle enemyRec = {enemies[j].pos.x - 20, enemies[j].pos.y - 20, 40,
                              40};
        if (CheckCollisionRecs(playerRec, enemyRec)) {
          DrawText("HITTED!", screenWidth / 2 - 50, screenHeight / 2, 40, RED);
        }
      }
    }
    BeginDrawing();
    ClearBackground(BLACK);
    DrawPlayer(&hero);
    DrawEnemies(enemies);
    DrawText(TextFormat("SCORE: %05i", score), 10, 10, 20, GREEN);
    DrawText("WASD: Move  SPACE: Shoot", 10, screenHeight - 30, 20, GRAY);
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
