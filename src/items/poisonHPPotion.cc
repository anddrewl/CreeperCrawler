#include "poisonHPPotion.h"

PoisonHealthPotion::PoisonHealthPotion(Player* player, double magnify) : Potion (player, POTION_PH, magnify){}

PoisonHealthPotion::~PoisonHealthPotion(){}

void PoisonHealthPotion::update() {
    Player* player = this->getTarget();
    int hp = std::max(0, (int)(player->getHP() - 10 * this->getMagnify()));
    player->setHP(hp);
}
