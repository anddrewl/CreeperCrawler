#ifndef ___WALL_H___
#define ___WALL_H___

#include "cell.h"

class Wall : public Cell {

    public:
        bool isWalkable() override;
};

#endif