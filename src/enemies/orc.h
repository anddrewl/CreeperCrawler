#ifndef ___ORC_H___
#define ___ORC_H___

#include "enemy.h"

class Orc : public Enemy {
    public:
        Orc(string race);
        Orc(int hp, int atk, int def, string race, char symbol, double extraDamage);
        ~Orc();
        int calculateDamageToPlayer(string playerRace, int playerDef) override;
        bool isMovable() override;

};

#endif