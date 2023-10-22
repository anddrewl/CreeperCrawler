#include "halfling.h"
#include <cstdlib>
#include <ctime>


Halfling::Halfling(string race) : Enemy(100, 15, 20, race, ENEMY_HALFING), chance(0.5){};
Halfling::Halfling (int hp, int atk, int def, string race, char symbol, double chance) : Enemy(hp, atk, def, race, symbol), chance(chance){};
Halfling::~Halfling(){}

int Halfling::getChance(){
    return chance;
}

void Halfling::setChance(double chance){
    this->chance = chance;
}

bool Halfling::chanceToMiss(){
    int r = std::rand();
    double rv = static_cast<double>(r) / RAND_MAX;
    return (rv < chance);
}


bool Halfling::isMovable(){
    return true;
}