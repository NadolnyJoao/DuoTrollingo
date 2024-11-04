#include "button.h"
#include "../globals.h"
#include <stddef.h>

Button create_button(float width, float height, Vector2 pos, Action on_click) {
    Button button = {0};

    button.bounds = (Rectangle){
        .width = width,
        .height = height,
        .x = pos.x,
        .y = pos.y,
    };

    button.pos = pos;

    /*button.parent = parent;*/

    button.texture = EMPTY_TEXTURE;

    button.on_click = on_click;

    return button;
}

void update_button(Button *button, Vector2 pos) {

    button->pos = pos;
    button->bounds.x = pos.x;
    button->bounds.y = pos.y;

    // if clicking inside the button
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {

        Vector2 mouse_pos = GetMousePosition();

        if (CheckCollisionPointRec(mouse_pos, button->bounds)) {

            // do
            if (button->on_click) {
                button->on_click(button);
            }
        }
    }
}

void draw_button(Button *button) {

    DrawRectangleRec(button->bounds, BLANK);
    DrawTextureV(button->texture, button->pos, WHITE);

    if (button->text != NULL) {
        /*int text_width = MeasureText(button->text, button->font_size);*/
        /*int text_height = button->font_size;*/
        Vector2 text_size = MeasureTextEx(button->font, button->text, button->font_size, 1);

        float text_x = button->bounds.x + (button->bounds.width / 2.0f) - (text_size.x / 2.0f);

        /* dont even ask */
        float text_y = button->bounds.y + button->bounds.height / 2 - text_size.y / 2.0f;

        DrawTextEx(button->font, button->text, (Vector2){text_x, text_y}, button->font_size, 1, theme.text_color);
    }
}
