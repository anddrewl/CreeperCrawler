#include "treasure.h"
#include "../items/itemDecorator.h"
#include "../items/smallTreasure.h"
#include "../items/normalTreasure.h"
#include "../items/dragonTreasure.h"
#include "../items/merchantHoard.h"

Treasure::Treasure (Player* p, string name, int gold) : ItemDecorator(p, name), gold(gold) {}

Treasure::~Treasure(){}

int Treasure::getGold(){
    return gold;
}

void Treasure::setGold(int g){
    gold = g;
}

bool Treasure::isTreasure(char sym){
    return (sym >= '6' && sym <= '9');
}

Treasure* Treasure::createTreasure(Player* player, char symbol){
    Treasure* t;
    switch (symbol)
    {
        case '6':
            t = new NormalTreasure(player);
            break;
        case '7':
            t = new SmallTreasure(player);
            break;
        case '8':
            t = new MerchantTreasure(player);
            break;
        case '9':
            t = new DragonTreasure(player);
            break;
        default:
            break;
    }
    return t;
}
