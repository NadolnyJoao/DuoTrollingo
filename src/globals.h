#ifndef GLOBALS_H
#define GLOBALS_H

#include "../raylib/raylib.h"

extern float screen_width;
extern float screen_height;

extern Vector2 mouse_pos;

extern const Texture2D EMPTY_TEXTURE;

/*extern Color background_color;*/
/*extern Color accent_color;*/
/*extern Color accent_color2;*/

typedef struct Theme {

        Color background_color;
        Color text_color;

        Color accent_color;
        Color accent_color2;
        Color accent_color3;
} Theme;

extern Theme theme;

typedef enum {
    MENU,
    LESSON_MENU,
    LESSON,
} CurrentState;

extern CurrentState current_state;

typedef enum {
    TUTORIAL,
} LessonNumber;

extern LessonNumber lesson_number;

extern Font iosevka;

void setup_theme(void);

#endif // GLOBALS_H
