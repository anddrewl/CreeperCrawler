#include "elf.h"

Elf::Elf(string race) : Enemy(140, 30, 10, race, ENEMY_ELF), extraAtk(2) {}
Elf::Elf(int hp, int atk, int def, string race, char symbol, int extraAtk) : Enemy(hp, atk, def, race, symbol), extraAtk(extraAtk){}

bool Elf::isMovable(){
    return true;
}

int Elf::attackPlayer(string playerRace, int playerDef) {
    int amount = Enemy::attackPlayer(playerRace, playerDef);
    if( playerRace != DROW){
        amount += Enemy::attackPlayer(playerRace, playerDef);
    }
    return amount;
}
