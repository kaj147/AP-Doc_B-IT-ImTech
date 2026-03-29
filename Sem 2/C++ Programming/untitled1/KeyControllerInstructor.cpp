//
// Created by Christophe on 12/02/2026.
//
#include "raylib.h"
#include "KeyControllerInstructor.h"
#include "Starter.h"

void KeyController() {
    Vector2 vector {800/2,600/2};
    Vector2 vectorSpeed {1,1};

    int width = 800;
    int height = 600;

    int widthOffset = 45;
    int heightOffset = 20;

    WindowCreator(width, height);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        //Keydown opdracht: werkt enkel in qwerty layout dus z is w en a is q rest is oke

        if (IsKeyDown(KEY_Q) && vector.x > 0) {
            vector.x -= vectorSpeed.x;
        }
        if (IsKeyDown(KEY_E) && vector.x < (width - widthOffset)) {
            vector.x += 1;
        }
        if (IsKeyDown(KEY_W) && vector.y > 0) {
            vector.y -= 1;
        }
        if (IsKeyDown(KEY_S) && vector.y < (height - heightOffset)) {
            vector.y += 1;
        }

        if (IsKeyDown(KEY_P)) {
            CloseWindow();
            return;
        }


        DrawText("DVD", vector.x, vector.y, 20, GREEN);
        EndDrawing();
    }
}
