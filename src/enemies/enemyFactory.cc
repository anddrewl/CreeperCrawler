#include "enemyFactory.h"

Enemy* EnemyFactory::createEnemy(char en, string race){
    Enemy* enemy;
    switch(en){
        case ENEMY_HUMAN:
            enemy = new Human(race);
            break;
        case ENEMY_DWARF:
            enemy = new Dwarf(race);
            break;
        case ENEMY_ELF:
            enemy = new Elf(race);
            break;
        case ENEMY_HALFING:
            enemy = new Halfling(race);
            break;
        case ENEMY_MERCHANT:
            enemy = new Merchant(race);
            break;
        case ENEMY_ORC:
            enemy = new Orc(race);
            break;
        case ENEMY_DRAGON:
             enemy = new Dragon(race);
             break;
        default:
             enemy = nullptr;
    }
    return enemy;
}