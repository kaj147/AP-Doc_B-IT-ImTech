
#ifndef THE_MONSTER_LAB_HERO_H
#define THE_MONSTER_LAB_HERO_H
#include "raylib.h"

namespace Game {
    class Hero {
    private:
        Texture2D image;
        Vector2 position;
    public:
        Hero();
        Hero(Vector2 position);

        void Update();
        Vector2 GetPosition() const;
        void Draw() const;

        ~Hero();
    };
}

#endif //THE_MONSTER_LAB_HERO_H