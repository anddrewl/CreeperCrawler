#include "restoreHPPotion.h"


RestoreHealthPotion::RestoreHealthPotion(Player* p, double magnify) : Potion (p, POTION_RH, magnify) {}

RestoreHealthPotion::~RestoreHealthPotion(){}

void RestoreHealthPotion::update() {
    Player* player = this->getTarget();
    int hp = std::min(player->getMaxHp(), (int)(player->getHP() + 10 * this->getMagnify()));
    player->setHP(hp);
}
