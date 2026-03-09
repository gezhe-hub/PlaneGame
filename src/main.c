#include "player.h"
#include "raylib.h"
int main() {
  const int screenWidth = 600;
  const int screenHeight = 800;
  InitWindow(screenWidth, screenHeight, "Plane Game - v0.1");
  SetTargetFPS(60);
  Player hero;
  InitPlayer(&hero);
  while (!WindowShouldClose()) {
    UpdatePlayer(&hero);
    BeginDrawing();
    ClearBackground(DARKGRAY);

    DrawPlayer(&hero);

    DrawText("Movement: WASD", 10, 10, 20, LIGHTGRAY);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
