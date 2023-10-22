#include "entity.h"

Entity::Entity(){}

Entity::~Entity(){}

int Entity::getX(){
    return x;
}

void Entity::setX(int n){
    x = n;
}

int Entity::getY(){
    return y;
}

void Entity::setY(int n){
    y = n;
}

char Entity::getSymbol(){
    return symbol;
}

void Entity::setSymbol(char c){
    symbol = c;
}
