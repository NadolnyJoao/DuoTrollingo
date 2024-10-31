#include "button.h"
#include "panel.h"

Button create_button(float width, float height, Vector2 pos, Panel *parent, Texture2D texture, Action on_click) {
    Button button = {0};

    button.bounds = (Rectangle){
        .width = width,
        .height = height,
        .x = pos.x,
        .y = pos.y,
    };

    button.pos = pos;

    button.parent = parent;

    button.texture = texture;

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
}
