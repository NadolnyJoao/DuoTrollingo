#ifndef PANEL_H
#define PANEL_H

#include "../../raylib/raylib.h"

typedef enum {
    ROUNDED_PANEL,
    RECTANGULAR_PANEL,
    OUTLINE_ROUNDED_PANEL,
    OUTLINE_RECTANGULAR_PANEL
} PanelType;

typedef struct Panel {
        Rectangle rect;
        Vector2 pos;
        Color color;
        PanelType panel_type;
} Panel;

Panel create_panel(float width, float heigth, Vector2 pos, Color color, PanelType type);

void update_panel(Panel *panel, Vector2 pos, Color color);

void draw_panel(Panel *panel);

#endif // !PANEL_H
