#ifndef ___HALFLING_H___
#define ___HALFING_H___

#include "enemy.h"

class Halfling : public Enemy {
    private: 
        double chance;

    public:
        Halfling(string race);
        Halfling (int hp, int atk, int def, string race, char symbol, double change);
        ~Halfling();
        int getChance();
        void setChance(double chance);
        bool chanceToMiss();
        bool isMovable() override;
};

#endif