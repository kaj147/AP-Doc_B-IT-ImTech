

#include "Mad_scientist.h"

#include "Monster.h"
#include <cmath>


namespace Game {
    Mad_scientist::Mad_scientist() :position({800,25}){
        image = LoadTexture("../Assets/scientist.png");
    }
    Vector2 Mad_scientist::GetPosition() const {
        return position;
    }
    void Mad_scientist::Mutate(Monster& monster) {



        if (std::abs(monster.GetPosition().x-position.x)<50 && std::abs(monster.GetPosition().y-position.y)<50)
           monster.triggerUpgrade();

            //monster.color = RED;
    }

    void Mad_scientist::Draw() {
    DrawTextureV(image,position,WHITE);
    }

    Mad_scientist::~Mad_scientist() {
        UnloadTexture(image);
    }
}
