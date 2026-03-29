#include <iostream>
#include <vector>
#include "raylib.h"
#include "Monster.h"
#include "Hero.h"
#include "raymath.h"

Vector2 screen = {1200, 800};

Hero* hero;

std::string path = "../the monster lab sprites/lab-background.png";

int main()
{
    std::vector<Game::Monster*> monsters;

    InitWindow(screen.x, screen.y, "GAMER");
    hero = new Hero();
    SetTargetFPS(60);

    Texture backgrnd = LoadTexture(path.data());

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        int deleteCounter = 0;
        int deleteIndex = 0;

        Game::Monster* deleteMon;

        DrawTextureEx(backgrnd,{0,00},0,0.6,WHITE);

        if (IsKeyDown(KEY_S) && monsters.size() <= 5)
        {
            Vector2 pos = {float(GetRandomValue(0, (screen.x - 150))), float(GetRandomValue(0, (screen.y - 150)))};
            monsters.push_back(new Game::Monster(pos));
        }

        for (auto monster : monsters)
        {
            //std::cout << "monster x: " <<monster->getPosition().x << " monster y: " << monster->getPosition().y << std::endl;
            //std::cout << "hero x: " <<hero->getLocation().x << " hero y: " << hero->getLocation().y << std::endl;

            if (std::abs(monster->getPosition().x - hero->getLocation().x) < 50 || std::abs((monster->getPosition().x - 150) - (hero->getLocation().x - 200)) < 50)
            {
                if (std::abs(monster->getPosition().y - hero->getLocation().y) < 50 || std::abs((monster->getPosition().y - 150) - (hero->getLocation().y - 200)) < 50)
                {
                    deleteMon = monster;
                    deleteIndex = deleteCounter;
                }
            }

            deleteCounter++;
            monster->Draw();
        }

        hero->Draw();
        hero->CheckKeys(screen);
        EndDrawing();

        if (deleteMon != nullptr)
        {
            delete deleteMon;
            monsters.erase(monsters.begin()+deleteIndex);
            deleteMon = nullptr;
        }
    }
}