//
// Created by Christophe on 12/02/2026.
//

#include "raylib.h"
#include "Bouncer.h"
#include "Starter.h"


void Bouncy() {
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

        DrawText("DVD", vector.x, vector.y, 20, GREEN);

        //DVD Logo bouncing
        if (((vector.x + vectorSpeed.x) >= (width - widthOffset)) || ((vector.x + vectorSpeed.x) <= 0)) {
            vectorSpeed.x = -vectorSpeed.x;
        }
        if (((vector.y + vectorSpeed.y) >= (height - heightOffset)) || ((vector.y + vectorSpeed.y) <= 0)) {
            vectorSpeed.y = -vectorSpeed.y;
        }

        vector.x += vectorSpeed.x;
        vector.y += vectorSpeed.y;

        EndDrawing();
    }
}