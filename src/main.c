#include "../raylib/raylib.h"

int main(void) {

    InitWindow(800, 600, "DuoTrollingo");

    SetTargetFPS(60);

    float screen_width = GetScreenWidth();
    float screen_heigth = GetScreenHeight();

    Rectangle quadrado = {
        .width = 100,
        .height = 100,
    };

    Vector2 quadrado_pos = {screen_width - quadrado.width / 2, screen_heigth - quadrado.height / 2};

    quadrado.x = quadrado_pos.x;
    quadrado.y = quadrado_pos.y;

    while (!WindowShouldClose()) {

        BeginDrawing();
        {
            ClearBackground(BLACK);

            DrawRectangleRec(quadrado, RED);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
