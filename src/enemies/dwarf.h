#ifndef ___DWARF_H___
#define ___DWARF_H___

#include "enemy.h"

class Dwarf : public Enemy {
    public:
        Dwarf(string race);
        Dwarf(int hp, int atk, int def, string race, char symbol);
        ~Dwarf();
        bool isMovable() override;

};

#endif