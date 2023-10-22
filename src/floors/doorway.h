#ifndef ___DOORWAY_H___
#define ___DOORWAY_H___

#include "cell.h"

class Doorway : public Cell {

    public:
        bool isWalkable() override;
};

#endif