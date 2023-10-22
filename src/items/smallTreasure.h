#ifndef SMALLTREASURE_H
#define SMALLTREASURE_H

#include "treasure.h"


class SmallTreasure : public Treasure {
    public:
        SmallTreasure(Player* p);
        ~SmallTreasure();
        void update();
};

#endif
