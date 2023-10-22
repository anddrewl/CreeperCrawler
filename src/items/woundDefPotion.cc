#include "woundDefPotion.h"

WoundDefPotion::WoundDefPotion(Player* p, double magnify) : Potion (p, POTION_WD, magnify) {}

WoundDefPotion::~WoundDefPotion(){} 

void WoundDefPotion::update() {
    Player* target = this->getTarget();
    target->setDef(target->getDef() - 5 * this->getMagnify());
}
