//
// Created by StevenCharpentier(ad on 14/03/2026.
//

#include "Hero.h"

namespace Game {
    Hero::Hero() :Hero({200,200}){

    }

    Hero::Hero(Vector2 position):
    position(position),
    image(LoadTexture("../Assets/hero.png")) {

    }

    void Hero::Update() {
        if (IsKeyDown(KEY_W))
            position.y-=3;
        if (IsKeyDown(KEY_A))
            position.x-=3;
        if (IsKeyDown(KEY_D))
            position.x+=3;
        if (IsKeyDown(KEY_S))
            position.y+=3;
    }

    Vector2 Hero::GetPosition() const {
        return position;
    }
    void Hero::Draw() const {
    DrawTexture(image,position.x,position.y,WHITE);
    }

    Hero::~Hero() {
        UnloadTexture(image);
    }
}
