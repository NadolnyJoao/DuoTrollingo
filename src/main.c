#include "../raylib/raylib.h"
#include "include/panel.h"
#include <stdbool.h>
#include <stdio.h>

#define WINDOW_SIZE_FACTOR 75.0f

float screen_width = 0;
float screen_height = 0;
float delta_time = 0;
Vector2 mouse_pos = {0};

int main(void) {

    InitWindow(16 * WINDOW_SIZE_FACTOR, 9 * WINDOW_SIZE_FACTOR, "DuoTrollingo");
    InitAudioDevice();

    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();

    Vector2 panel_pos = {-250, 10};

    // -25 -> open
    // -250 -> closed

    bool panel_open = false;

    Panel side_panel = create_panel(300,            // width  ( 1/4 of the screen = 300)
                                    655,            // height (screen height - 20 = 655)
                                    panel_pos,      // pos
                                    GRAY,           // color
                                    ROUNDED_PANEL); // type of panel

    Rectangle button = {
        .x = (side_panel.pos.x / 4),
        .y = 40,
        .width = 45,
        .height = 45,
    };

    Sound snd_button = LoadSound("/src/assets/sound/snd_button.mp3");
    bool button_act = false;
    Image button_img = LoadImage("src/assets/image/3lines.png");
    ImageResize(&button_img, button.width, button.height);
    Texture2D button_texture = LoadTextureFromImage(button_img);
    UnloadImage(button_img);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        delta_time = GetFrameTime();
        mouse_pos = GetMousePosition();

        if (IsKeyDown(KEY_SPACE) && panel_open == false) {
            panel_pos.x = -25;
            panel_open = true;
            PlaySound(snd_button);
        }

        if (IsKeyDown(KEY_W) && panel_open == true) {
            panel_pos.x = -250;
            panel_open = false;
        }

        update_panel(&side_panel, panel_pos, GRAY);

        button.x = (side_panel.pos.x + side_panel.rect.width) - 60;

        Vector2 buttton_pos = {button.x, button.y};

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mouse_pos, button)) {
            printf("oi\n");
            PlaySound(snd_button);
        }

        BeginDrawing();
        {
            ClearBackground(LIGHTGRAY);
            draw_panel(&side_panel);
            DrawRectangleRec(button, BLANK);
            DrawTexture(button_texture, button.x, button.y, WHITE);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
