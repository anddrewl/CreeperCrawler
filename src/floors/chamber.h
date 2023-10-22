#ifndef CHAMBER_H
#define CHAMBER_H
#include <iostream>
#include "cell.h"
#include "../chamberCrawler.h"
#include "../constants.h"
#include "../enemies/enemy.h"
#include "../enemies/enemyFactory.h"
#include "../character.h"
#include "../items/itemDecorator.h"
#include "../items/smallTreasure.h"
#include "../items/normalTreasure.h"
#include "../items/dragonTreasure.h"
#include "../items/boostAtkPotion.h"
#include "../items/boostDefPotion.h"
#include "../items/woundAtkPotion.h"
#include "../items/woundDefPotion.h"
#include "../items/poisonHPPotion.h"
#include "../items/restoreHPPotion.h"
#include "stair.h"
#include <vector>
#include <cstdlib>
using namespace std;

class Potion;

class Chamber {
    private:
        int id;
        vector<Cell*> chamberCells;

    public:
        Chamber(int id);
        ~Chamber();
        void renderPotion();
        ItemDecorator* renderTreasure();
        void renderEnemy();
        void renderStairs();
        void addCell(Cell* c);
        Cell* getRandomCell();
        int getChamberID();
};

#endif
