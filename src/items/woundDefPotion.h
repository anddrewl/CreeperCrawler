#ifndef WOUNDDEF_H
#define WOUNDDEF_H

#include "potion.h"

class WoundDefPotion : public Potion {
    public:
       WoundDefPotion(Player* p, double magnify);
       ~WoundDefPotion();
       void update(); 
};

#endif