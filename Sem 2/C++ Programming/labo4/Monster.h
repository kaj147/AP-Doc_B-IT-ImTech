//
// Created by Christophe on 05/03/2026.
//

#ifndef LABO4_GAME_H
#define LABO4_GAME_H
using namespace std;

#include <raylib.h>
#include <string>

namespace Game
{
    class Monster
    {
    private:
        struct MonsterStats
        {
            float speed;
            int power;
            int mutationLevel = 0;
        };
        MonsterStats stats;

        friend void PerformExperiment(Game::Monster& m);

    public:
        Monster();

        Monster(Vector2 pos);

        Vector2 getPosition();

        void Draw();
        bool EnemyClose(Vector2 distance);

        ~Monster();
    };
}



#endif //LABO4_GAME_H