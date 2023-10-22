#ifndef DRAGONTREASURE_H
#define DRAGONTREASURE_H

#include "treasure.h"

class DragonTreasure : public Treasure {
    public:
        DragonTreasure(Player* p);
        ~DragonTreasure();
        void update();
};

#endif
