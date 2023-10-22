#ifndef ___PASSAGE_H___
#define ___PASSAGE_H___

#include "cell.h"

class Passage : public Cell {

    public:
        bool isWalkable() override;
};

#endif