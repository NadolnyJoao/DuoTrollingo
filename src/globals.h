#ifndef GLOBALS_H
#define GLOBALS_H

#include "../raylib/raylib.h"

typedef enum {
    MENU,
    LESSON_MENU,
    LESSON,
} CurrentState;

extern CurrentState current_state;

extern Font iosevka;

#endif // GLOBALS_H
