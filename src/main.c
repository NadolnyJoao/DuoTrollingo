#include "../raylib/raylib.h"
#include "include/panel.h"

#define WINDOW_SIZE_FACTOR 75.0f

float screen_width = 0;
float screen_height = 0;

int main(void) {

    InitWindow(16 * WINDOW_SIZE_FACTOR, 9 * WINDOW_SIZE_FACTOR, "DuoTrollingo");

    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();

    Panel side_panel = create_panel(screen_width / 4.0f,   // width
                                    screen_height - 20.0f, // height
                                    (Vector2){20, 10},     // pos
                                    GRAY,                  // color
                                    RECTANGULAR_PANEL);    // type of panel

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
        {
            ClearBackground(LIGHTGRAY);
            draw_panel(&side_panel);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
