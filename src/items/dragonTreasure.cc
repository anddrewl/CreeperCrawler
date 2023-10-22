#include "dragonTreasure.h"

DragonTreasure::DragonTreasure(Player* p) : Treasure(p, GOLD_DRAGON, 6) {}

DragonTreasure::~DragonTreasure(){}

void DragonTreasure::update() {
    Player* player = this->getTarget();
    player->setGold(player->getGold() + this->getGold());
}
