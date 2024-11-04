#ifndef BUTTON_H
#define BUTTON_H

#include "../../raylib/raylib.h"
#include "panel.h"

/* this has to be forward declared or the signatures of the function pointer dont match the ones of the struct */
struct Button;

typedef void (*Action)(struct Button *button);

typedef struct Button {
        Rectangle bounds;
        Color color;
        Texture2D texture;
        Vector2 pos;
        bool at_pos1;
        Panel *parent;
        Action on_click;
        int screen_id;
        char *text;
        int font_size;
        Font font;

} Button;

Button create_button(float width, float height,
                     Vector2 pos,
                     Action on_click);

void update_button(Button *button, Vector2 pos);

void draw_button(Button *button);

#endif // !BUTTON_H
