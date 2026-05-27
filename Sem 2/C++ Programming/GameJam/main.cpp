#include <iostream>

int main() {
    InitWindow(screen.x, screen.y, "GAMER");
    SetTargetFPS(60);

    //Texture backgrnd = LoadTexture(path.data());

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
		DrawTextureEx(backgrnd,{0,00},0,0.6,WHITE);

		//code

        EndDrawing();
	}
    return 0;
}