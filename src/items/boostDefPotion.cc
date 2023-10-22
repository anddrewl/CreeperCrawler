#include "boostDefPotion.h"

BoostDefPotion::BoostDefPotion(Player* p, double magnify) : Potion(p, POTION_BD, magnify) {}

BoostDefPotion::~BoostDefPotion(){}

void BoostDefPotion::update() {
    Player* player = this->getTarget();
    player->setDef(player->getDef() + 5 * this->getMagnify());
}
