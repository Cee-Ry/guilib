#include <raylib.h>

int main() {
    InitWindow(250, 250, "My Game");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}   
