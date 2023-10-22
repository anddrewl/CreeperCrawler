#include "boostAtkPotion.h"

BoostAtkPotion::BoostAtkPotion(Player* p, double magnify) : Potion(p, POTION_BA, magnify) {}

BoostAtkPotion::~BoostAtkPotion(){}

void BoostAtkPotion::update() {
    Player* player = this->getTarget();
    player->setAtk(player->getAtk() + 5 * this->getMagnify());
}
