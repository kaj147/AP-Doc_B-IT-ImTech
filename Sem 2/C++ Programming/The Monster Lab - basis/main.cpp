#include <iostream>
#include <vector>


#include "raylib.h"
#include "Game/Constants.h"
#include "Game/Hero.h"
#include "Game/Monster.h"

struct test {
    std::string value;
    test(std::string _value):value(_value){}
    ~test() {
    }
};
int main() {

    auto monsterList = std::vector<Game::Monster*>();

    InitWindow(screenWidth, screenHeight, "Hello World");
    auto backdrop = LoadTexture("../Assets/lab-background.png");
    SetTargetFPS(60);

    Vector2 HeroStart = { screenWidth/2-100, screenHeight/2 -100};
    Game::Hero* hero = new Game::Hero(HeroStart);
    Game::Mad_scientist* mad_scientist = new Game::Mad_scientist();

    while (!WindowShouldClose()) {
        BeginDrawing();

        DrawTextureEx(backdrop,{0,00},0,0.6,WHITE);

        if (IsKeyPressed(KEY_Y))
            monsterList.push_back( new Game::Monster(Vector2(rand()%screenWidth,rand()%screenHeight)));

        Game::Monster* deletemon;

        int deletecounter=0;
        int deleteindex=0;

        mad_scientist->Draw();

        for (auto monster:monsterList) {
            mad_scientist->Mutate(*monster);

            if (std::abs(monster->GetPosition().x-hero->GetPosition().x)<50 && std::abs(monster->GetPosition().y-hero->GetPosition().y)<50) {
                deletemon= monster;
                deleteindex=deletecounter;
            };

            monster->move(hero->GetPosition(),mad_scientist->GetPosition());
            monster->Draw();
            deletecounter++;
        }

        hero->Update();
        hero->Draw();
        EndDrawing();
        if (deletemon !=nullptr) {
            delete deletemon;
            monsterList.erase(monsterList.begin()+deleteindex);
            deletemon = nullptr;

        }
    }

    return 0;
}