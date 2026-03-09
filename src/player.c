#include "player.h"
void UpdatePlayer(Player *p) {
  if (IsKeyDown(KEY_W))
    p->pos.y -= p->speed;
  if (IsKeyDown(KEY_S))
    p->pos.y += p->speed;
  if (IsKeyDown(KEY_A))
    p->pos.x -= p->speed;
  if (IsKeyDown(KEY_D))
    p->pos.x += p->speed;
  if (p->pos.x < 0)
    p->pos.x = 0;
  if (p->pos.x > 600)
    p->pos.x = 600;
  if (p->pos.y < 0)
    p->pos.y = 0;
  if (p->pos.y > 800)
    p->pos.y = 800;
  if (IsKeyPressed(KEY_SPACE)) {
    for (int i = 0; i < MAX_BULLETS; i++) {
      if (!p->bullets[i].active) {
        p->bullets[i].active = true;
        p->bullets[i].pos = (Vector2){p->pos.x, p->pos.y};
        break;
      }
    }
  }
  for (int i = 0; i < MAX_BULLETS; i++) {
    if (p->bullets[i].active) {
      p->bullets[i].pos.y -= p->bullets[i].speed;
      if (p->bullets[i].pos.y < 0) {
        p->bullets[i].active = false;
      }
    }
  }
}
void DrawPlayer(Player *p) {
  DrawTriangle((Vector2){p->pos.x, p->pos.y - 20},
               (Vector2){p->pos.x - 20, p->pos.y + 20},
               (Vector2){p->pos.x + 20, p->pos.y + 20}, YELLOW);
  for (int i = 0; i < MAX_BULLETS; i++) {
    if (p->bullets[i].active) {
      DrawCircleV(p->bullets[i].pos, 5, RED);
    }
  }
}
void InitPlayer(Player *p) {
  p->pos = (Vector2){300, 700};
  p->speed = 5.0f;
  p->hp = 3;
  for (int i = 0; i < MAX_BULLETS; i++) {
    p->bullets[i].active = false;
    p->bullets[i].speed = 7.0f;
  }
}
