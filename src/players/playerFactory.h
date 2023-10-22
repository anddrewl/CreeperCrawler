#ifndef ___PLAYERFACTORY_H___
#define ___PLAYERFACTORY_H___

#include <string>
#include "../constants.h"
#include "player.h"

using namespace std;

class Player;

class PlayerFactory{
    public:
        static Player* createPlayer(string race);
};

#endif
