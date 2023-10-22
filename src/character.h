#ifndef ___CHARACTER_H___
#define ___CHARACTER_H___

 
#include <string>
#include "constants.h"
#include "entity.h"

using namespace std;
class Character : public Entity{
    private:
        int hp, atk, def;
        int default_hp, default_atk, default_def;
        string race;
    public:
        Character();
        Character(int hp, int atk, int def, string race);
        virtual ~Character();
        int getHP ();
        void setHP(int hp);
        int getDefaultHP();
        void setDefaultHP(int hp);
        int getAtk();
        void setAtk(int atk);
        int getDefaultAtk();
        void setDefaultAtk(int atk);
        int getDef();
        void setDef(int def);
        int getDefaultDef();
        void setDefaultDef(int def);
        virtual bool isDead() = 0;
       
};

#endif

