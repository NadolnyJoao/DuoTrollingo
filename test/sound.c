#include <raylib.h>

int main(void) {

    InitWindow(800, 600, "TEST");
    InitAudioDevice();

    Sound test_sound = LoadSound("snd_button.wav");

    while (!WindowShouldClose()) {

        BeginDrawing();
        {
            PlaySound(test_sound);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
