#include "normalTreasure.h"

NormalTreasure::NormalTreasure(Player* p) : Treasure(p, GOLD_NORMAL, 2) {}

NormalTreasure::~NormalTreasure() {}

void NormalTreasure::update() {
    Player* player = this->getTarget();
    player->setGold(player->getGold() + this->getGold());
}
