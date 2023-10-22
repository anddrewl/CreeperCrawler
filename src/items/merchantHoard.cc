#include "merchantHoard.h"


MerchantTreasure::MerchantTreasure(Player* player) : Treasure(player, GOLD_MERCHANT, 4) {}

MerchantTreasure::~MerchantTreasure(){}

void MerchantTreasure::update() {
    Player* player = this->getTarget();
    player->setGold(player->getGold() + this->getGold());
}
