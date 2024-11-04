#include "globals.h"
#include "../raylib/raylib.h"

CurrentState current_state = MENU;

Font iosevka = {0};

Vector2 mouse_pos = {0};

const Texture2D EMPTY_TEXTURE = {0};

float screen_width;
float screen_height;

/*Color background_color = {0};*/
/*Color accent_color = {0};*/
/*Color accent_color2 = {0};*/

Theme theme = {
    .background_color = {0},
    .text_color = {0},

    .accent_color = {0},
    .accent_color2 = {0},
    .accent_color3 = {0},
};

void setup_theme(void) {
    theme.background_color = GetColor(0x181818FF);
    theme.text_color = WHITE;

    theme.accent_color = GetColor(0x3b3b3bFF);
    theme.accent_color2 = GetColor(0x323232FF);
    theme.accent_color3 = GetColor(0x34363aFF);
}
