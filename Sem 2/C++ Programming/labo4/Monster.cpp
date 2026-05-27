//
// Created by Christophe on 05/03/2026.
//

#include "Monster.h"
#include "raylib.h"
#include <iostream>
#include "raymath.h"
#include "Hero.h"

Texture2D img1;
string path1;

Texture2D img2;
string path2;

Texture2D img3;
string path3;

Texture2D img4;
string path4;

Vector2 position;

namespace Game {

    Monster::Monster() {
        path1 = "../the monster lab sprites/monster_128.png";
        path2 = "../the monster lab sprites/enhanced_monster.png";
        path3 = "../the monster lab sprites/bulked_monster.png";
        path4 = "../the monster lab sprites/ascended_monster.png";

        if (FileExists(path1.data()))
        {
            img1 = LoadTexture(path1.data());
            img1.width = 150;
            img1.height = 150;
        }
        if (FileExists(path2.data()))
        {
            img2 = LoadTexture(path2.data());
            img2.width = 150;
            img2.height = 150;
        }
        if (FileExists(path3.data()))
        {
            img3 = LoadTexture(path3.data());
            img3.width = 150;
            img3.height = 150;
        }
        if (FileExists(path4.data()))
        {
            img4 = LoadTexture(path4.data());
            img4.width = 150;
            img4.height = 150;
        }
        else
        {
            cout << "Monster could not be loaded" << endl;
        }
    };

    Monster::Monster(Vector2 pos) :Monster()
    {
        path1 = "../the monster lab sprites/monster_128.png";
        path2 = "../the monster lab sprites/enhanced_monster.png";
        path3 = "../the monster lab sprites/bulked_monster.png";
        path4 = "../the monster lab sprites/ascended_monster.png";

        if (FileExists(path1.data()))
        {
            img1 = LoadTexture(path1.data());
            img1.width = 150;
            img1.height = 150;
        }
        if (FileExists(path2.data()))
        {
            img2 = LoadTexture(path2.data());
            img2.width = 150;
            img2.height = 150;
        }
        if (FileExists(path3.data()))
        {
            img3 = LoadTexture(path3.data());
            img3.width = 150;
            img3.height = 150;
        }
        if (FileExists(path4.data()))
        {
            img4 = LoadTexture(path4.data());
            img4.width = 150;
            img4.height = 150;
        }
        else
        {
            cout << "Monster could not be loaded" << endl;
        }
    }

    void Monster::Draw()
    {
        switch (this->stats.mutationLevel)
        {
        case 0:
            DrawTexture(img1, position.x, position.y, WHITE);
            break;
        case 1:
            DrawTexture(img2, position.x, position.y, WHITE);
            break;
        case 2:
            DrawTexture(img3, position.x, position.y, WHITE);
            break;
        case 3:
            DrawTexture(img4, position.x, position.y, WHITE);
            break;
        }
    }

    Vector2 Monster::getPosition() {
        return position;
    }

    Monster::~Monster()
    {
        UnloadTexture(img1);
        std::cout << "Monster unloaded" << std::endl;
    }
}
