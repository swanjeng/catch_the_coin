#include "raylib.h"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
#define TITLE "接金幣遊戲"
#define BACKGROUND_COLOR (Color){1, 130, 129, 255}
#define COIN_COLOR (Color){255, 192, 0, 255}
#define COIN_RADIUS 20
#define BOX_COLOR (Color){196, 164, 132, 255}
#define BOX_WIDTH 75
#define BOX_HEIGHT 100
#define SCORE_COLOR (Color){255, 255, 255, 255}
#define BOX_SPEED 5
#define COIN_SPEED 5

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(60);

    Vector2 box_pos = {0, SCREEN_HEIGHT - BOX_HEIGHT};
    Vector2 coin_pos = {GetRandomValue(COIN_RADIUS, SCREEN_WIDTH - COIN_RADIUS), 0};
    int score = 0;
    
    while (!WindowShouldClose()) {
        if (coin_pos.y >= SCREEN_HEIGHT + COIN_RADIUS) {
            coin_pos = (Vector2){GetRandomValue(COIN_RADIUS, SCREEN_WIDTH - COIN_RADIUS), 0};
        }
        if (SCREEN_HEIGHT - BOX_HEIGHT - COIN_RADIUS <= coin_pos.y && coin_pos.y <= SCREEN_HEIGHT - BOX_HEIGHT && box_pos.x <= coin_pos.x && coin_pos.x <= box_pos.x + BOX_WIDTH) {
            coin_pos = (Vector2){GetRandomValue(COIN_RADIUS, SCREEN_WIDTH - COIN_RADIUS), 0};
            score ++;
        } else {
            coin_pos.y += COIN_SPEED;
        }

        if (IsKeyDown(KEY_RIGHT)) box_pos.x += BOX_SPEED;
        if (box_pos.x > SCREEN_WIDTH - BOX_WIDTH) box_pos.x = SCREEN_WIDTH - BOX_WIDTH;
        if (IsKeyDown(KEY_LEFT)) box_pos.x -= BOX_SPEED;
        if (box_pos.x < 0) box_pos.x = 0;

        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        DrawCircleV(coin_pos, COIN_RADIUS, COIN_COLOR);
        DrawRectangleV(box_pos, (Vector2){BOX_WIDTH, BOX_HEIGHT}, BOX_COLOR);
        DrawText(TextFormat("Score: %d", score), 10, 10, 30, SCORE_COLOR);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}