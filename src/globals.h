#ifndef GLOBALS_H
#define GLOBALS_H

#include "../raylib/raylib.h"

extern float screen_width;
extern float screen_height;

extern Vector2 mouse_pos;

extern const Texture2D EMPTY_TEXTURE;

extern Color background_color;
extern Color accent_color;
extern Color accent_color2;

typedef enum {
    MENU,
    LESSON_MENU,
    LESSON,
} CurrentState;

extern CurrentState current_state;

extern Font iosevka;

#endif // GLOBALS_H
