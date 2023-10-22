#ifndef ___TILE_H___
#define ___TILE_H___

#include "cell.h"

class Tile : public Cell {

    public:
        bool isWalkable() override;
};

#endif