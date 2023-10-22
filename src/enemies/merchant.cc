#include "merchant.h"

bool Merchant::hostile = false;

Merchant::Merchant(string race) : Enemy(30, 70, 5, race, ENEMY_MERCHANT) {};
Merchant::Merchant(int hp, int atk, int def, string race, char symbol) : Enemy(hp, atk, def, race, symbol){}

Merchant::~Merchant(){}


 bool Merchant::isHostile(){
    return hostile;
 }

void  Merchant::setHostile(){
    hostile = true;
}

bool Merchant::isMovable(){
    return true;
}
