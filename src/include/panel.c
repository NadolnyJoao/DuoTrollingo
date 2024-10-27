#include "panel.h"

Panel create_panel(float width, float heigth, Vector2 pos, Color color, PanelType type) {

    Panel panel;

    panel.pos = pos;

    Rectangle rect = {
        .x = panel.pos.x,
        .y = panel.pos.y,
        .width = width,
        .height = heigth,
    };

    panel.rect = rect;

    panel.color = color;

    panel.panel_type = type;

    return panel;
}

void draw_panel(Panel *panel) {

    if (panel->panel_type == ROUNDED_PANEL) {
        DrawRectangleRounded(panel->rect,   // rectangle -> pos, size
                             0.2,           // roundness
                             10,            // segments
                             panel->color); // color
    }

    if (panel->panel_type == RECTANGULAR_PANEL) {
        DrawRectangleRec(panel->rect, panel->color);
    }

    return;
}
