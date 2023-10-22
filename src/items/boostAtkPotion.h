#ifndef BOOSTATTACK_H
#define BOOSTATTACK_H

#include "potion.h"

class BoostAtkPotion : public Potion {
    public:
        BoostAtkPotion(Player* p, double magnify);
        ~BoostAtkPotion();
        void update();
};

#endif
