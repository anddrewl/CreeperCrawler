#include "human.h"

Human::Human(string race) : Enemy(140, 20, 20, race, ENEMY_HUMAN), goldToDrop(2){}

Human::Human(int hp, int atk, int def, string race, char symbol, int goldToDrop) : Enemy(hp, atk, def, race, symbol), goldToDrop(goldToDrop){}

Human::~Human(){}

bool Human::isMovable(){
    return true;
}
