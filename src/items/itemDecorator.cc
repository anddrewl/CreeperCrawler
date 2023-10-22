#include "itemDecorator.h"


ItemDecorator::ItemDecorator(Player* target, string name) : target(target), name(name){}

ItemDecorator::~ItemDecorator() {
    delete target;
}

 Player* ItemDecorator::getTarget(){
    return target;
 }

void ItemDecorator::setTarget(Player* p) {
    target = p;
}

void ItemDecorator::update(){
    
}

 string ItemDecorator::getName(){
    return name;
 }

void ItemDecorator::setName(string s){
    name = s;
}
