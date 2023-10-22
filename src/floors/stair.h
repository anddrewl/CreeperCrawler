#ifndef ___STAIR_H___
#define ___STAIR_H___

#include "cell.h"

class Stair : public Cell {

    public:
        bool isWalkable() override;
};

#endif