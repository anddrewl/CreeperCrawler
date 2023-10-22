#include "player.h"
#include <algorithm>
#include "../items/treasure.h"

using namespace std;

Player* Player::instance = nullptr;

string Player::race = SHADE;

 

Player::Player(int hp, int atk, int def, string race, int maxHP, int gold) : Character(hp, atk, def, race){
    this->setMaxHp(maxHP);
    this->setGold(gold);
    this->setSymbol(SYM_PLAYER);
    this->setCellSymbol(SYM_TILE);
}


Player::~Player() {
    delete instance;
    setInstance();
}

void Player::setRace(string s){
    race = s;
}

Player* Player::getInstance() {
    if(instance == nullptr){
        instance = PlayerFactory::createPlayer(race);
    }
    return instance;
}

void Player::setInstance() {
    instance = nullptr;
}

int Player::getGold() {
    return gold;
}

void Player::setGold(int g) {
    gold = g;
}

int Player::getMaxHp() {
    return maxHp;
}

void Player::setMaxHp(int mh) {
    maxHp = mh;
}

int Player::getScore(){
    int score = gold;
    if (Player::race == SHADE ){
        score *= 1.5;
    }
    return score;

}
void Player::takeDamage(int dmg) {
    setHP(std::max(getHP() - dmg, 0));
}

bool Player::isDead() {
    return getHP() == 0;
}

void Player::attackEnemy(Enemy* enemy){
    Halfling* h = dynamic_cast<Halfling*>(enemy);
    if (h) {
        bool b = h->chanceToMiss();
        if (!b) {
            int dmg = this->calculateDmgToEnemy(enemy->getDef());
            enemy->takeDamage(dmg);
            this->addReward(enemy);
        }
    }else {
        int dmg = this->calculateDmgToEnemy(enemy->getDef());
        enemy->takeDamage(dmg);
        this->addReward(enemy);
    }
}

int Player::calculateDmgToEnemy(int enemyDef){
     return std::ceil((100.0/(100.0 + enemyDef)) * this->getAtk());
}

string Player::getRace(){
    return race;
}


void Player::addReward(Enemy* en){
    
}

// char Player::getSymbol(){
//     return SYM_PLAYER;
// }

char Player::getCellSymbol(){
    return cellSymbol;
}

void Player::setCellSymbol(char symbol){
    cellSymbol = symbol;
}


void Player::move (Cell* nextCell, bool canPickupGold) {
    if(canPickupGold){
        Entity* entity = nextCell->getEntity();
       
            Treasure* treasure = dynamic_cast<Treasure*>(entity);
            if(treasure){
                this->setGold(this->getGold() + treasure->getGold());
                cellSymbol = SYM_TILE;
            }
    }else{
         cellSymbol = nextCell->getSymbol();

    }
    this->setX(nextCell->getRow());
    this->setY(nextCell->getCol());
   
    nextCell->setSymbol(SYM_PLAYER);
    nextCell->setEntity(this);
}


