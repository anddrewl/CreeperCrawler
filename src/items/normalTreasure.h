#ifndef NORMALTREASURE_H
#define NORMALTREASURE_H

#include "treasure.h"

class NormalTreasure : public Treasure {
    public:
        NormalTreasure(Player* p);
        ~NormalTreasure();
        void update();
};

#endif
