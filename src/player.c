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
}
void DrawPlayer(Player *p) {
  DrawTriangle((Vector2){p->pos.x, p->pos.y - 20},
               (Vector2){p->pos.x - 20, p->pos.y + 20},
               (Vector2){p->pos.x + 20, p->pos.y + 20}, YELLOW);
}
void InitPlayer(Player *p) {
  p->pos = (Vector2){300, 700};
  p->speed = 5.0f;
  p->hp = 3;
}
