#include "actions.h"
#include "include/button.h"

/* --------------------------------------------------------------------------------------------- */

void toggle_side_pannel(Button *button) {

    Vector2 panel_closed_pos = {-250, 10};
    Vector2 panel_open_pos = {-25, 10};

    if (button->parent->panel_open == false) {
        button->parent->pos = panel_open_pos;
    } else {
        button->parent->pos = panel_closed_pos;
    }

    button->parent->panel_open = !button->parent->panel_open;
}

/* --------------------------------------------------------------------------------------------- */

void goto_screen(Button *button) {
    current_state = button->screen_id;
}
