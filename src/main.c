#include "../raylib/raylib.h"

#define WINDOW_SIZE_FACTOR 75.0f

float screen_width = 0;
float screen_height = 0;

int main(void) {

    InitWindow(16 * WINDOW_SIZE_FACTOR, 9 * WINDOW_SIZE_FACTOR, "DuoTrollingo");

    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
        {
            ClearBackground(BLACK);

            DrawRectangle((screen_width / 2) - 50,  // pos x
                          (screen_height / 2) - 50, // pos y
                          100,                      // width
                          100,                      // height
                          RED);                     // color
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
