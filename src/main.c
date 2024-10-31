#include "../raylib/raylib.h"
#include "actions.h"
#include "include/button.h"
#include "include/panel.h"

#define WINDOW_SIZE_FACTOR 75.0f

float screen_width = 0;
float screen_height = 0;
Vector2 mouse_pos = {0};

Color background_color = {0};
Color accent_color = {0};

int main(void) {

    InitWindow(16 * WINDOW_SIZE_FACTOR, 9 * WINDOW_SIZE_FACTOR, "DuoTrollingo");
    /*SetExitKey(KEY_NULL);*/
    InitAudioDevice();

    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();

    background_color = GetColor(0x181818FF);
    accent_color = GetColor(0x3b3b3bFF);

    /* --------------------------------------------------------------------------------------------- */
    // SIDE PANEL DECLARATION

    Panel side_panel = create_panel(300,                 // width  ( 1/4 of the screen = 300)
                                    655,                 // height (screen height - 20 = 655)
                                    (Vector2){-250, 10}, // starting pos
                                    accent_color,        // color
                                    ROUNDED_PANEL);      // type of panel

    /* --------------------------------------------------------------------------------------------- */
    // SIDE PANEL EXPAND BUTTON DECLARATION

    Vector2 expand_panel_button_size = {45, 45};
    Image button_img = LoadImage("src/assets/image/3lines.png");
    ImageResize(&button_img, expand_panel_button_size.x, expand_panel_button_size.y);
    Texture2D button_texture = LoadTextureFromImage(button_img);
    UnloadImage(button_img);
    Button expand_panel_button = create_button(expand_panel_button_size.x, // width
                                               expand_panel_button_size.y, // height
                                               (Vector2){0, 0},            // pos (will be set relative to parent)
                                               &side_panel,                // parent
                                               button_texture,             // texture
                                               toggle_side_pannel);        // actions

    /* --------------------------------------------------------------------------------------------- */

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        mouse_pos = GetMousePosition();

        /* ------------------------------------------------------------------------------------------------ */
        // UPDATE FUNCTION CALLS

        update_panel(&side_panel,
                     side_panel.pos,
                     side_panel.color);

        update_button(&expand_panel_button,
                      (Vector2){
                          (side_panel.pos.x + side_panel.rect.width) - 60, // x position relative to parent
                          40});                                            // y pos

        /* ------------------------------------------------------------------------------------------------- */

        BeginDrawing();
        {
            ClearBackground(background_color);

            /* --------------------------------------------------------------------------------------------- */
            // DRAW CALLS

            draw_panel(&side_panel);
            draw_button(&expand_panel_button);
        }
        EndDrawing();

        /* ------------------------------------------------------------------------------------------------ */
    }
    UnloadTexture(button_texture);
    CloseWindow();

    return 0;
}
