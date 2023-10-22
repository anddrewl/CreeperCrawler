#ifndef POTION_H
#define POTION_H

#include "itemDecorator.h"
#include <algorithm>

class Potion : public ItemDecorator {
    private:
        double magnify;

    public:
        Potion(Player* player, string name, double magnify);
        ~Potion();
        double getMagnify();
        void setMaginify(double magnify);
        static bool isPotion(char symbol);
        static Potion* createPotion(Player* player, char symbol, double magnify);
};

#endif