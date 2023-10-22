#include "smallTreasure.h"

SmallTreasure::SmallTreasure (Player* p) : Treasure(p, GOLD_SMALL, 1) {}

SmallTreasure::~SmallTreasure() {}

void SmallTreasure::update() {
    Player* player = this->getTarget();
    player->setGold(player->getGold() + this->getGold());
}
