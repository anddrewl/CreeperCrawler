#ifndef ___ENEMY_H___
#define ___ENEMY_H___

#include <string>
#include "../character.h"
#include "../floors/cell.h"
#include <cmath>
#include <algorithm>

class Enemy : public Character{
    private:
        char symbol;
        bool movable;
        bool isMoved;

    public:
    
        Enemy(int hp, int atk, int def, string race, char symbol);
        ~Enemy() override;
        char getSymbol();
        void setSymbol(char symbol);
        virtual int attackPlayer(string playerRace, int playerDef);
        virtual bool isPlayerInRange(int px, int py);
        virtual void takeDamage(int damage);
        virtual int calculateDamageToPlayer(string playerRace, int playerDef);
        bool isDead() override;
        bool hasMoved();
        void setMoved(bool moved);
        int giveRewardToPlayer();
        void move(Cell* cell);
        static bool isEnemy(char c);
        virtual bool isMovable() = 0;
        
};

#endif