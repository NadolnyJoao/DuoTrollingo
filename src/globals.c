#include "globals.h"
#include "../raylib/raylib.h"

CurrentState current_state = MENU;

Font iosevka = {0};

Vector2 mouse_pos = {0};

const Texture2D EMPTY_TEXTURE = {0};

float screen_width;
float screen_height;

Color background_color = {0};
Color accent_color = {0};
Color accent_color2 = {0};
