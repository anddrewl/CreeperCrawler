#ifndef ITEMDECORATOR_H
#define ITEMDECORATOR_H

#include "../players/player.h"

class ItemDecorator : public Entity {
    private:
        Player* target;
        string name;

    public:
        ItemDecorator(Player* player, string name);
        ~ItemDecorator();
        Player* getTarget();
        void setTarget(Player *p);
        virtual void update();
        string getName();
        void setName(string s);
};



#endif