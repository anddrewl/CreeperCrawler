#include "orc.h"

Orc::Orc(string race) : Enemy(180, 30, 25, race, ENEMY_ORC){};

Orc::Orc(int hp, int atk, int def, string race, char symbol, double extraDamage) : Enemy(hp, atk, def, race, symbol){};

Orc::~Orc(){}

int Orc::calculateDamageToPlayer(string playerRace, int playerDef){
    int dmg = Enemy::calculateDamageToPlayer(playerRace, playerDef);
    if (playerRace == GOBLIN) {
        dmg *= 1.5;
    }
    return dmg;
}

bool Orc::isMovable(){
    return true;
}