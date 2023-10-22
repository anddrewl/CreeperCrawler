#include <limits.h>
#include "vampire.h"


Vampire::Vampire() : Player(50, 25, 25, VAMPIRE, INT_MAX, 0) {}

void Vampire::attackEnemy(Enemy* en) {
    
    Player::attackEnemy(en);
    Dwarf* d = dynamic_cast<Dwarf*>(en);
    if (d) {
        this->setHP(this->getHP() - 5);
    } else {
        this->setHP(this->getHP() + 5);
    }
    
}
