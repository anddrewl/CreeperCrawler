#include "chamber.h"

Chamber::Chamber(int id) : id{id}{}

Chamber::~Chamber() {}

void Chamber::renderEnemy() {
    int m = rand() % TOTAL_PROBABILITY_DISTRIBUTION;
    char enemyType;
    if (0 <= m && m < ENEMY_HUMAN_DISTRIBUTION) {
        enemyType = ENEMY_HUMAN;
    } else if (ENEMY_HUMAN_DISTRIBUTION <= m && m < ENEMY_DWARF_DISTRIBUTION) {
        enemyType = ENEMY_DWARF;
    } else if (ENEMY_DWARF_DISTRIBUTION <= m && m < ENEMY_HALFLING_DISTRIBUTION) {
        enemyType= ENEMY_HALFING; 
    } else if (ENEMY_HALFLING_DISTRIBUTION <= m && m < ENEMY_ELF_DISTRIBUTION) {
        enemyType = ENEMY_ELF;
    } else if (ENEMY_ELF_DISTRIBUTION <= m && m < ENEMY_ORC_DISTRIBUTION) {
        enemyType = ENEMY_ORC;
    } else {
        enemyType = ENEMY_MERCHANT;
    }

    Enemy* enemy = EnemyFactory::createEnemy(enemyType, Player::getRace());
    Cell* cell = getRandomCell();
    cell->setSymbol(enemyType);
    cell->setEntity(enemy);
    enemy->setX(cell->getRow());
    enemy->setY(cell->getCol());
}

ItemDecorator* Chamber::renderTreasure() {
    Cell* cell = getRandomCell();
    int m = rand() % 8;
    char e;
    ItemDecorator* gold;
    if (0 <= m && m < NORMAL_GOLD_DISTRIBUTION) {
        e = NORMAL_GOLD;
    } else if (NORMAL_GOLD_DISTRIBUTION <= m && m < DRAGON_GOLD_DISTRIBUTION) {
        e = DRAGON_GOLD;
    } else {
        e = SMALL_GOLD;
    }
    Player* player = Player::getInstance();
    switch(e){
        case NORMAL_GOLD:
            gold = new NormalTreasure(player);
            break;
        case SMALL_GOLD:
            gold = new SmallTreasure(player);
            break;
        case DRAGON_GOLD:   
            gold = new DragonTreasure(player);
            break;
        default:
            gold = nullptr;
            break;
    }
    cell->setSymbol(SYM_GOLD);
    cell->setEntity(gold);
    gold->setX(cell->getRow());
    gold->setY(cell->getCol());
    gold->setSymbol(SYM_GOLD);
    return gold;
 }

void Chamber::addCell(Cell* c) {
    chamberCells.push_back(c);
}

void Chamber::renderPotion() {
    Cell* cell = getRandomCell();
    int m = rand() % 6;
    Potion* potion;
    Player* player = Player::getInstance();
    double mag = 1;
    if(Player::getRace() == DROW){
        mag = POTION_MAGNIFY;
    }
    if (m == 0) {
       potion = new BoostAtkPotion(player, mag);  
    } else if (m == 1) {
        potion = new WoundAtkPotion(player, mag);
    } else if (m == 2) {
        potion = new BoostDefPotion(player, mag);
    } else if (m == 3) {
        potion = new WoundDefPotion(player, mag);
    } else if (m == 4) {
        potion = new RestoreHealthPotion(player, mag);
    } else {
        potion = new PoisonHealthPotion(player, mag);
    }
    cell->setSymbol(SYM_POTION);
    cell->setEntity(potion);
    potion->setX(cell->getRow());
    potion->setY(cell->getCol());
    potion->setSymbol(SYM_POTION);
}

void Chamber::renderStairs() {
    Cell* cell = getRandomCell();

    cell->setSymbol(SYM_STAIRS);
}

Cell* Chamber::getRandomCell(){
    Cell* cell = nullptr;
    do{
        cell = chamberCells.at(rand() % chamberCells.size());
    }while(cell->isOccupied());
    return cell;
}

int Chamber::getChamberID(){
    return id;
}
