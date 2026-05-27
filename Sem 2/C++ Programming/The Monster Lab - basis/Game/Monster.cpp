
#include "Monster.h"
#include "Monster.h"
#include "Monster.h"


#include <algorithm>
#include <random>
namespace Game {

    Monster::Monster():
    id(rand()),
    image(LoadTexture(stats.Levels[int(Level::hatchling)].data())),
    color(WHITE){};

    Monster::Monster(Vector2 positie) :Monster(){
        this->position = positie;

    }

    void Monster::move(Vector2 heroPos, Vector2 scientistPos) {
        // ik zet in mijn werking een upgrade cooldown op beweging, dit is geen deel van de opdracht, maar wel leuk extra gedrag.
        time_t currentTime = std::time(0);
        onCooldown = (currentTime - lastUpgradeTime < 5);

        // een willekeurig stapje, soms
        if (rand() % 10 == 0) {
            position.x += (rand() % 3) - 1; // -1, 0, of 1
            position.y += (rand() % 3) - 1;
            return;
        }

        Vector2 target;
        bool fleeing = false;


        float distToHero = sqrt(pow(position.x - heroPos.x, 2) + pow(position.y - heroPos.y, 2));

        if (distToHero < 300.0f) {
            // Vluchten: Beweeg in de tegenovergestelde richting van de held
            target = { position.x + (position.x - heroPos.x), position.y + (position.y - heroPos.y) };
            fleeing = true;
        }
        else if (!onCooldown) {
            // Richting de scientist bewegen
            target = scientistPos;
        }


        if (!onCooldown) {
            if (position.x < target.x) position.x++;
            else if (position.x > target.x) position.x--;

            if (position.y < target.y) position.y++;
            else if (position.y > target.y) position.y--;
        }
        else
        {
            if (position.x < target.x) position.x--;
            else if (position.x > target.x) position.x++;

            if (position.y < target.y) position.y--;
            else if (position.y > target.y) position.y++;
        }

        //zorg ervoor dat het monster niet buiten het scherm gaat
        position.x = std::clamp(int(position.x), 0, screenWidth-image.width);
        position.y = std::clamp(int(position.y), 0, screenHeight-image.height);
    }

    void Monster::triggerUpgrade() {
        if (onCooldown)
            return;

        isUpgraded = true;
        lastUpgradeTime = time(0);

        if (stats.currentLevel==Level::ascended)
            return;
                UnloadTexture(image);
                stats.currentLevel++;
                image= LoadTexture(stats.Levels[static_cast<int>(stats.currentLevel)].data());

    }
    Vector2 Monster::GetPosition() const {
        return position;
    }
    void Monster::Draw() const{
        DrawTexture(image,position.x,position.y,color);
    }


    Monster::~Monster() {
        UnloadTexture(image);
    }
};