#include "../raylib/raylib.h"
#include "actions.h"
#include "include/button.h"
#include "include/panel.h"

#define WINDOW_SIZE_FACTOR 75.0f

float screen_width = 0;
float screen_height = 0;
float delta_time = 0;
Vector2 mouse_pos = {0};

int main(void) {

    InitWindow(16 * WINDOW_SIZE_FACTOR, 9 * WINDOW_SIZE_FACTOR, "DuoTrollingo");
    /*SetExitKey(KEY_NULL);*/
    InitAudioDevice();

    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();

    Panel side_panel = create_panel(300,                  // width  ( 1/4 of the screen = 300)
                                    655,                  // height (screen height - 20 = 655)
                                    (Vector2){-250, 10},  // pos
                                    GetColor(0x3b3b3bFF), // color
                                    ROUNDED_PANEL);       // type of panel
    Vector2 expand_panel_button = {45, 45};

    Image button_img = LoadImage("src/assets/image/3lines.png");
    ImageResize(&button_img, expand_panel_button.x, expand_panel_button.y);
    Texture2D button_texture = LoadTextureFromImage(button_img);
    UnloadImage(button_img);

    Button test_button = create_button(expand_panel_button.x, // width
                                       expand_panel_button.y, // height
                                       (Vector2){0, 0},       // pos
                                       &side_panel,           // parent
                                       button_texture,        // texture
                                       toggle_side_pannel);   // action

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        delta_time = GetFrameTime();
        mouse_pos = GetMousePosition();

        update_panel(&side_panel,
                     side_panel.pos,
                     side_panel.color);

        update_button(&test_button,
                      (Vector2){
                          (side_panel.pos.x + side_panel.rect.width) - 60, // x position relative to parent
                          40});                                            // y pos

        BeginDrawing();
        {
            ClearBackground(GetColor(0x181818FF));
            draw_panel(&side_panel);

            draw_button(&test_button);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
