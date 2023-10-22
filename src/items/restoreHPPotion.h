#ifndef RESTOREHP_H
#define RESTOREHP_H

#include "potion.h"

class RestoreHealthPotion : public Potion {
    public:
        RestoreHealthPotion(Player* p, double magnify);
        ~RestoreHealthPotion();
        void update();
};

#endif