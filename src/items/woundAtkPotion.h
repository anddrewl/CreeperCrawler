#ifndef WOUNDATK_H
#define WOUNDATK_H

#include "potion.h"

class WoundAtkPotion : public Potion{
    public:
       WoundAtkPotion(Player* p, double magnify);
       ~WoundAtkPotion();
       void update(); 
};

#endif