
#pragma once
#include <ctime>
#include <map>
#include <string>

#include "Mad_scientist.h"
#include "../raylib.h"

#include "Constants.h"

namespace Game {

    class Monster {
        friend class Mad_scientist;
    private:
        enum class Level {
            hatchling=0,
            enhanced=1,
            bulked=2,
            ascended=3

        };
        friend Level& operator++(Level& l) {
            l = static_cast<Level>(static_cast<int>(l) + 1);

            // Boundary check
            if (l == Level::ascended) l = Level::ascended;

            return l;
        }
        friend Level operator++(Level& l, int) {
            Level temp = l;
            ++l;
            return temp;
        }
        struct Monsterstats{
            float speed=1;
            static constexpr std::string_view Levels[]={
                "../Assets/monster_128.png",
                "../Assets/enhanced_monster.png",
                "../Assets/bulked_monster.png",
                "../Assets/ascended_monster.png"
            };
            Level currentLevel=Level::hatchling;

        };
        Texture2D image;

        Monsterstats stats;
        Vector2 position;
        bool isUpgraded = false;
        std::time_t lastUpgradeTime = 0;
        Color color;
        const int id;
        bool onCooldown;

        void triggerUpgrade();



    public:
        Monster();
        Monster(Vector2 positie);

        void move(Vector2 heroPos, Vector2 scientistPos);
        Vector2 GetPosition() const;
        void Draw() const;

        ~Monster();

    };
} // Game
