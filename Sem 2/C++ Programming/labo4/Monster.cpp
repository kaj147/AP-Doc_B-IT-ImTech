//
// Created by Christophe on 05/03/2026.
//

#include "Monster.h"
#include "raylib.h"
#include <iostream>
#include "raymath.h"
#include "Hero.h"


namespace Game {

    Monster::Monster() {
        path = "../the monster lab sprites/monster_128.png";

        if (FileExists(path.data()))
        {
            img = LoadTexture(path.data());
            img.width = 150;
            img.height = 150;
        }
        else
        {
            std::cout << "Monster could not be loaded" << std::endl;
        }
    };

    Monster::Monster(Vector2 pos) :Monster()
    {

        if (FileExists(path.data()))
        {
            position = pos;
        }
        else
        {
            std::cout << "Monster could not be loaded" << std::endl;
        }
    }

    void Update()
    {

    }

    void Monster::Draw()
    {
        DrawTexture(img, position.x, position.y, WHITE);
    }

    Vector2 Monster::getPosition() {
        return position;
    }

    Monster::~Monster()
    {
        UnloadTexture(img);
        std::cout << "Monster unloaded" << std::endl;
    }
}
