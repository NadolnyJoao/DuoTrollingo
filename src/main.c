#include "../raylib/raylib.h"
#include "actions.h"
#include "globals.h"
#include "include/button.h"
#include "include/panel.h"

#define WINDOW_SIZE_FACTOR 75.0f

int main(void) {

    InitWindow(16 * WINDOW_SIZE_FACTOR, 9 * WINDOW_SIZE_FACTOR, "DuoTrollingo");
    /*SetExitKey(KEY_NULL);*/
    InitAudioDevice();

    iosevka = LoadFontEx("src/assets/Iosevka-Light.ttf", 50, 0, 250); // magic numbers

    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();

    background_color = GetColor(0x181818FF);
    accent_color = GetColor(0x3b3b3bFF);
    accent_color2 = GetColor(0x323232FF);

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
                                               toggle_side_pannel);        // actions
    expand_panel_button.parent = &side_panel;
    expand_panel_button.texture = button_texture;

    /* --------------------------------------------------------------------------------------------- */
    // menu panel

    Panel menu_panel = create_panel(300,
                                    150,
                                    (Vector2){(screen_width / 2.0f) - (300.0f / 2.0f), screen_height / 2},
                                    accent_color,
                                    ROUNDED_PANEL);

    Button menu_button = create_button(menu_panel.rect.width,
                                       menu_panel.rect.height,
                                       menu_panel.pos,
                                       goto_screen);

    menu_button.parent = &menu_panel;
    menu_button.texture = EMPTY_TEXTURE;
    menu_button.screen_id = LESSON_MENU;
    menu_button.font_size = 45;
    menu_button.text = "Start Learning";

    Image menu_img = LoadImage("src/assets/image/placeholder.png");
    ImageResize(&menu_img, menu_panel.rect.width, menu_panel.rect.width);
    Texture2D menu_texture = LoadTextureFromImage(menu_img);
    UnloadImage(menu_img);

    /* --------------------------------------------------------------------------------------------- */

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        // STUFF THAT HAS TO BE UPDATED EVERYWHERE
        mouse_pos = GetMousePosition();

        switch (current_state) {
        case MENU: {
            /* --------------------------------------------------------------------------------------------- */
            // update calls
            update_panel(&menu_panel, menu_panel.pos, menu_panel.color);

            update_button(&menu_button, menu_panel.pos);

            /* --------------------------------------------------------------------------------------------- */
            // DRAW CALLS

            BeginDrawing();
            {
                ClearBackground(background_color);
                draw_panel(&menu_panel);
                draw_button(&menu_button);

                // menu logo

                DrawTexture(menu_texture,
                            screen_width / 2.0f - menu_texture.width / 2.0f,
                            15,
                            WHITE);
            }
            EndDrawing();
        }

        break;

        /* --------------------------------------------------------------------------------------------- */
        case LESSON_MENU: {
            BeginDrawing();
            {
                ClearBackground(background_color);
                DrawText("WORK IN PROGRESS", screen_width / 4, screen_height / 2, 40, RED);
            }
            EndDrawing();
        }

        break;

            /* --------------------------------------------------------------------------------------------- */

        case LESSON: {

            /* --------------------------------------------------------------------------------------------- */
            // UPDATE CALLS
            update_panel(&side_panel, side_panel.pos, side_panel.color);

            update_button(&expand_panel_button,
                          (Vector2){
                              (side_panel.pos.x + side_panel.rect.width) - 60, // x position relative to parent
                              40});                                            // y pos

            /* --------------------------------------------------------------------------------------------- */
            // DRAW CALLS
            BeginDrawing();
            {
                ClearBackground(background_color);
                draw_panel(&side_panel);
                draw_button(&expand_panel_button);
            }
            EndDrawing();
        }

        break;
        }
    }
    UnloadTexture(button_texture);
    CloseWindow();

    return 0;
}
