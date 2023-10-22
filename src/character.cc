#include "character.h"

Character::Character(){};

Character::~Character(){};

Character::Character(int hp, int atk, int def, string race) 
    : hp(hp), atk(atk), def(def), default_hp(hp), default_atk(atk), default_def(def), race(race){}

int Character::getHP(){
    return hp;
}

void Character::setHP(int hp){
    this->hp = hp;
}

int Character::getDefaultHP(){
    return default_hp;
}

void Character::setDefaultHP(int hp){
    default_hp = hp;
}

int Character::getAtk(){
    return atk;
}

void Character::setAtk(int atk){
    this->atk = atk;
}

int Character::getDefaultAtk(){
    return def;
}

void Character::setDefaultAtk(int atk){
    this->default_atk = atk;
}


int Character::getDef(){
    return def;
}

void Character::setDef(int def){
    this->def = def;
}

int Character::getDefaultDef(){
    return default_def;
}

void Character::setDefaultDef(int def){
    default_def = def;
}
