#ifndef ___DRAGON_H___
#define ___DRAGON_H___

#include "enemy.h"
#include "../items/dragonTreasure.h"

class Dragon : public Enemy {
    private: 
        DragonTreasure * hoard;

    public:
        Dragon(string race);
        Dragon(int hp, int atk, int def, string race, char symbol);
        ~Dragon();
        DragonTreasure* getHoard();
        void setTreasureHoard(DragonTreasure* hoard);
        bool isMovable() override;
        bool isPlayerInRange(int px, int py) override;
};

#endif