
#ifndef THE_MONSTER_LAB_MAD_SCIENTIST_H
#define THE_MONSTER_LAB_MAD_SCIENTIST_H
#include "raylib.h"

namespace Game {
    class Monster;

    class Mad_scientist {
    private:
        Texture2D image;
        Vector2 position;
    public:
        Mad_scientist();
        Vector2 GetPosition() const;
        void Mutate(Monster& monster);
        void Draw();

        ~Mad_scientist();

    };
}

#endif //THE_MONSTER_LAB_MAD_SCIENTIST_H