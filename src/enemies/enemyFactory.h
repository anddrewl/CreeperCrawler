#ifndef ___ENEMYFACTORY_H___
#define ___ENEMYFACTORY_H___

#include <string>
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "merchant.h"
#include "orc.h"
#include "dragon.h"

using namespace std;

class EnemyFactory{
    public:
        static Enemy* createEnemy(char en, string race);
};

#endif
