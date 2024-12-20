#include "panel.h"
#include "../globals.h"
#include <stddef.h>

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

    panel.panel_open = false;

    panel.panel_type = type;

    return panel;
}

void update_panel(Panel *panel, Vector2 pos, Color color) {

    panel->pos = pos;
    panel->rect.x = pos.x;
    panel->rect.y = pos.y;

    panel->color = color;

    return;
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

    if (panel->panel_type == OUTLINE_ROUNDED_PANEL) {
        DrawRectangleRoundedLines(panel->rect,
                                  0.2, // roundness
                                  10,  // segments
                                  5,   // line thickness
                                  panel->color);

        DrawRectangleRounded(panel->rect,
                             0.2,
                             10,
                             panel->color);
    }

    if (panel->panel_type == OUTLINE_RECTANGULAR_PANEL) {
        DrawRectangleLinesEx(panel->rect,
                             5, // line thickness
                             panel->color);
    }

    if (panel->text != NULL) {
        /*int text_width = MeasureText(button->text, button->font_size);*/
        /*int text_height = button->font_size;*/
        Vector2 text_size = MeasureTextEx(panel->font, panel->text, panel->font_size, 1);

        float text_x = panel->rect.x + (panel->rect.width / 2.0f) - (text_size.x / 2.0f);

        /* dont even ask */
        float text_y = panel->rect.y + panel->rect.height / 2 - text_size.y / 2.0f;

        DrawTextEx(panel->font, panel->text, (Vector2){text_x, text_y}, panel->font_size, 1, theme.text_color);
    }

    return;
}
