#include "woundAtkPotion.h"

WoundAtkPotion::WoundAtkPotion(Player* p, double magnify) : Potion (p, POTION_WA, magnify) {}

WoundAtkPotion::~WoundAtkPotion(){}

void WoundAtkPotion::update() {
    Player* target = this->getTarget();
    target->setAtk(target->getAtk() - 5 * this->getMagnify());
}

