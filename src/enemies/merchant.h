#ifndef ___MERCHANT_H___
#define ___MERCHANT_H___

#include "enemy.h"

class Merchant : public Enemy {
    public:
        static bool hostile;
        Merchant(string race);
        Merchant(int hp, int atk, int def, string race, char symbol);
        ~Merchant();
        static bool isHostile();
        static void setHostile();
        bool isMovable() override;
        
};

#endif