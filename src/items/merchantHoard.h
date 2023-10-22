#ifndef MERCHANTTREASURE_H
#define MERCHANTTREASURE_H

#include "treasure.h"

class MerchantTreasure : public Treasure {
    public:
        MerchantTreasure(Player* player);
        ~MerchantTreasure();
        void update();
};

#endif
