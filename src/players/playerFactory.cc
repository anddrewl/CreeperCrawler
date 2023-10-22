
#include "playerFactory.h"
#include "shade.h"
#include "troll.h"
#include "drow.h"
#include "vampire.h"
#include "goblin.h"

Player* PlayerFactory::createPlayer(string race){
    Player* player;
    if ( race == SHADE){
        player = new Shade();
    } else if ( race == TROLL){
        player = new Troll();
    } else if ( race == DROW){
        player = new Drow();
    } else if ( race == VAMPIRE ) {
        player = new Vampire();
    } else if ( race == GOBLIN) {
        player = new Goblin();
    } else {
        player = nullptr;
    }
    return player;
}

