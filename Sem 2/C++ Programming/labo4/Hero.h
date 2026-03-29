//
// Created by Christophe on 05/03/2026.
//

#ifndef LABO4_HERO_H
#define LABO4_HERO_H
#include <string>

#include "raylib.h"


class Hero
{
private:
    Vector2 location;
    std::string path;
    Texture2D texture;
    bool loaded;
    float movementSpeed;

public:
    Vector2 getLocation()
    {
        return location;
    }

    void CheckKeys(Vector2 screen);
    void Draw();
    Hero();
    ~Hero();
};


#endif //LABO4_HERO_H