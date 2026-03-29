//
// Created by Christophe on 05/03/2026.
//

#ifndef LABO4_GAME_H
#define LABO4_GAME_H

#include <raylib.h>
#include <string>

namespace Game
{
    class Monster
    {
    private:
        Texture2D img;
        Vector2 position;
        std::string path;

        /*struct MonsterStats
        {
            float speed;
            int power;
        };
        MonsterStats stats;*/
        int mutationLevel = 1;

        friend void PerformExperiment(Game::Monster& m);

    public:
        Monster();

        Monster(Vector2 pos);

        Vector2 getPosition();

        void Update();
        void Draw();
        bool EnemyClose(Vector2 distance);

        ~Monster();
    };
}



#endif //LABO4_GAME_H