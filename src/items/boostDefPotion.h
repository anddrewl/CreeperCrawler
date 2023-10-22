#ifndef BOOSTDEFPOTION_H
#define BOOSTDEFPOTION_H

#include "potion.h"

class BoostDefPotion : public Potion {
    public:
        BoostDefPotion(Player* p, double magnify);
        ~BoostDefPotion();
        void update();
};

#endif
