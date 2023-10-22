#ifndef POISONHP_H
#define POISONHP_H

#include "potion.h"

class PoisonHealthPotion : public Potion {
    public:
        PoisonHealthPotion(Player* p, double magnify);
        ~PoisonHealthPotion();
        void update();
};



#endif