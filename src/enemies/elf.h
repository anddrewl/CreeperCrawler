#ifndef ___ELF_H___
#define ___ELF_H___

#include "enemy.h"

class Elf : public Enemy {
    private: 
        int extraAtk;

    public:
        Elf(string race);
        Elf(int hp, int atk, int def, string race, char symbol, int extraAtk);
        bool isMovable() override;
        virtual int attackPlayer(string playerRace, int playerDef);
};

#endif