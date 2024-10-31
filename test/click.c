#include <raylib.h>
#include <stdbool.h>

int main(void) {

    InitWindow(800, 600, "TEST");
    SetTargetFPS(60);

    Vector2 pos1 = {100, 100};
    Vector2 pos2 = {600, 400};

    Rectangle square = {pos1.x, pos1.y, 50, 50};

    bool at_pos1 = true;

    while (!WindowShouldClose()) {
        Vector2 mouse_pos = GetMousePosition();

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {

            if (CheckCollisionPointRec(mouse_pos, square)) {

                if (at_pos1) {
                    square.x = pos2.x;
                    square.y = pos2.y;
                } else {
                    square.x = pos1.x;
                    square.y = pos1.y;
                }

                at_pos1 = !at_pos1;
            }
        }

        BeginDrawing();
        {
            ClearBackground(GetColor(0x181818FF));

            DrawRectangleRec(square, YELLOW);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
