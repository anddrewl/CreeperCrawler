#include "enemy.h"
#include "algorithm"

Enemy::Enemy(int hp, int atk, int def, string race, char symbol) : Character(hp, atk, def, race), symbol(symbol){}

Enemy::~Enemy(){}

char Enemy::getSymbol(){
    return symbol;
}

void Enemy::setSymbol(char symbol){
    this->symbol = symbol;
}

bool Enemy::isEnemy(char symbol){
    auto it = std::find(begin(ENEMY_SYMS), std::end(ENEMY_SYMS), symbol);
    return (it != std::end(ENEMY_SYMS));
}

int Enemy::attackPlayer(string playerRace, int playerDef){
    int x = rand() % 2;
    int dmg = 0;
    if (x == 0) {
        dmg = calculateDamageToPlayer(playerRace, playerDef);
    }
    return dmg;
}

bool Enemy::isPlayerInRange(int px, int py){
    return std::abs(px - this->getX()) <= 1 && std::abs(py - this->getY()) <= 1;
}

void Enemy::takeDamage(int damage){
    this->setHP(std::max(this->getHP() - damage, 0));
}

int Enemy::calculateDamageToPlayer(string playerRace, int playerDef){
    return std::ceil((100.0/(100.0 + playerDef)) * this->getAtk());
}

bool Enemy::isDead(){
    return this->getHP() == 0;
}

int Enemy::giveRewardToPlayer(){
    return 0;
}

bool Enemy::hasMoved(){
    return isMoved;
}

void Enemy::setMoved(bool moved){
    isMoved = moved;
}

void Enemy::move(Cell* cell){
    this->setX(cell->getRow());
    this->setY(cell->getCol());
    cell->setSymbol(this->getSymbol());
    cell->setEntity(this);
    isMoved = true;
}



