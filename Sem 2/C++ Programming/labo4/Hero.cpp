//
// Created by Christophe on 05/03/2026.
//

#include "Hero.h"

#include <iostream>
#include <ostream>

Hero::Hero()
{
    location = {0,0};

    movementSpeed = 5;
    loaded = false;
    path = "../the monster lab sprites/hero.png";


    if (FileExists(path.data()) && !loaded)
    {
        texture = LoadTexture(path.data());
        texture.width = 200;
        texture.height = 200;
        loaded = true;
    }
}

void Hero::CheckKeys(Vector2 screen)
{
    if (IsKeyDown(KEY_LEFT) && location.x > 0)
    {
        location.x -= movementSpeed;
        //std::cout << location.x << std::endl;
    }
    if (IsKeyDown(KEY_RIGHT) && location.x < (screen.x - 200))
    {
        location.x += movementSpeed;
        //std::cout << location.x << std::endl;
    }

    if (IsKeyDown(KEY_UP) && location.y > 0)
    {
        location.y -= movementSpeed;
        //std::cout << location.y << std::endl;
    }
    if (IsKeyDown(KEY_DOWN) && location.y < (screen.y - 200))
    {
        location.y += movementSpeed;
        //std::cout << location.y << std::endl;
    }
}

void Hero::Draw()
{

    if (loaded)
    {
        DrawTexture(texture, location.x, location.y, WHITE);
    }
    else
    {
        std::cout << "Hero NOT loaded" << std::endl;
    }
}

Hero::~Hero() {
    UnloadTexture(texture);
}