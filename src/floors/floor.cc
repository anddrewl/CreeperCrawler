#include "floor.h"
#include <map>

using namespace std;

class Chamber;
class Cell;

std::map<std::string, std::string> directionMap = {{NORTH, "North"}, {SOUTH, "South"}, {WEST, "West"}, {EAST, "East"},
{NORTH_WEST, "North West"}, {NORTH_EAST, "North East"}, {SOUTH_WEST, "South West"}, {SOUTH_EAST, "South East"}};
Floor::Floor() {

    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            cells[i][j] = new Cell(i, j, ' ');
        }
    }

    for (int i = 0; i < MAX_CHAMBERS; i++) {
        chambers[i] = new Chamber(i);
    }
}

Floor::~Floor() {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            delete cells[i][j];
            cells[i][j] = nullptr;
        }
    }

    for (int i = 0; i < MAX_CHAMBERS; i++) {
       delete chambers[i];
       chambers[i] = nullptr;
    }
}

bool Floor::isValidSymbol(char symbol){
    return symbol == SYM_TILE || symbol == SYM_PLAYER || Enemy::isEnemy(symbol) || symbol == SYM_STAIRS ||
                 Potion::isPotion(symbol) || Treasure::isTreasure(symbol);
}
void Floor::loadFromFile(ifstream *floorStream) {
    string line;
    for (int i = 0; i < MAX_ROW; i++) {
        getline(*floorStream, line);
        for (int j = 0; j < MAX_COLUMN; j++) {
            cells[i][j]->setSymbol(line[j]);
            char symbol = line[j];
            if (isValidSymbol(symbol)) {
                int chamberID = locateChamber(i, j);
                cells[i][j]->setChamberID(chamberID);
                chambers[chamberID]->addCell(cells[i][j]);
                if( symbol == SYM_TILE){
                    cells[i][j]->setEntity(nullptr);
                } else if( symbol == SYM_PLAYER ){
                    Player* player = Player::getInstance();
                    player->setX(i);
                    player->setY(j);
                    player->setCellSymbol(SYM_TILE);
                    cells[i][j]->setEntity(player);
                } else if ( Enemy::isEnemy(symbol)){
                    Enemy* enemy = EnemyFactory::createEnemy(symbol, Player::getRace());
                    cells[i][j]->setEntity(enemy);
                    enemy->setX(i);
                    enemy->setY(j);
                } else if ( Potion::isPotion(symbol)){
                    double mag = 1;
                    if(Player::getRace() == DROW){
                        mag = POTION_MAGNIFY;
                    }
                    
                        Potion* p = Potion::createPotion(Player::getInstance(), symbol, mag);
                        cells[i][j]->setEntity(p);
                        cells[i][j]->setSymbol(SYM_POTION);
                        p->setX(i);
                        p->setY(j);
               
                } else if ( Treasure::isTreasure(symbol)){
                    Treasure* treasure = Treasure::createTreasure(Player::getInstance(), symbol);
                    cells[i][j]->setEntity(treasure);
                    treasure->setX(cells[i][j]->getRow());
                    treasure->setY(cells[i][j]->getCol());
                    treasure->setSymbol(SYM_GOLD);
                    cells[i][j]->setSymbol(SYM_GOLD);
                }
            }
            else {
                 cells[i][j]->setChamberID(-1);
            }
        }
    }
}

int Floor::locateChamber(int i, int j) {
    if (3 <= i && i <= 6 && 3 <= j && j <=  29) {
        return 0;
    } else if (15 <= i && i <= 22 && 4 <= j && j <= 25) {
        return 1;
    } else if (10 <= i && i <= 12 && 38 <= j && j <= 50) {
        return 4;
    } else if ((16 <= i && i <= 18 && 65 <= j && j <= 75) 
            || (19 <= i && i <= 21 && 37 <= j && j <= 75 )) {
        return 3;
    } else {
        return 2;
    }
}

void Floor::displayFloor(string actionMsg, int level) {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            if (cells[i][j]) {
                char s = cells[i][j]->getSymbol();
                auto it = colorMap.find(s);
                if ( it != colorMap.end()){
                      cout << it->second << s << ANSI_RESET;
                } else {
                    cout << s; 
                }
            } else {
                cout <<  ' ';
            }
        }
        cout << endl;
    }
    Player* player = Player::getInstance();
    cout << "Race: " << Player::getRace() << " Gold: " << player->getGold() << "\t\t\t\t\t\t\tFloor " << level << endl; 
    cout << "HP: " << player->getHP() << endl;
    cout << "Atk: " << player->getAtk() << endl;
    cout << "Def: " << player->getDef() << endl;
    cout << "Action: " << actionMsg << endl;

}

Chamber* Floor::getRandomChamber() {
    return chambers[rand() % MAX_CHAMBERS];
}

void Floor::spawnPotions() {
    for (int i = 0; i < NUM_POTION; i++) {
        Chamber* cell = getRandomChamber();
        cell->renderPotion();
    }
}

void Floor::spawnEnemies() {
    for (int i = 0; i < NUM_ENEMY; i++) {
        Chamber* chamber = getRandomChamber();
        chamber->renderEnemy();
    }
}

 
void Floor::spawnTreasures() {
   
    for (int i = 0; i < NUM_TREASURES; i++) {
        Chamber* c = Floor::getRandomChamber();
        ItemDecorator* gold = c->renderTreasure();
        DragonTreasure* dt =  dynamic_cast<DragonTreasure*>(gold);
        if(dt){
            // spawn a dragon
            bool found = false;
            while(!found){
                string dir = DIRECTIONS[std::rand() % 8];
                Cell* cell = getNeighbourCell(dir, dt);
                if(!cell->isOccupied()){
                    // spawn a dragon to guard the DragonTreasure
                    found = true;
                    Enemy* enemy = EnemyFactory::createEnemy(ENEMY_DRAGON, Player::getRace());
                    cell->setSymbol(ENEMY_DRAGON);
                    cell->setEntity(enemy);
                    enemy->setX(cell->getRow());
                    enemy->setY(cell->getCol());
                }
            }
        }
    }
}

void Floor::spawnStairs() {
    Chamber* chamber =  getRandomChamber();
    chamber->renderStairs();   
}

Cell* Floor::getCell(int i, int j) {
    return cells[i][j];
}

void Floor::spawnPlayers(){
    Chamber* chosenChamber = getRandomChamber();
    Cell * cell = chosenChamber->getRandomCell();
    Player* player = Player::getInstance();
    player->setX(cell->getRow());
    player->setY(cell->getCol());
    player->setCellSymbol(SYM_TILE);
    cell->setSymbol(SYM_PLAYER);
    cell->setEntity(player);
}

void Floor::spawnFloor() {
    spawnStairs();
    spawnPotions();
    spawnTreasures();
    spawnEnemies();
}

bool Floor::canMovePlayer(Cell* cell){
    char symbol = cell->getSymbol();
    return (!cell->isOccupied()) || (symbol == SYM_DOORWAY) || (symbol == SYM_PASSAGE) || (symbol == SYM_STAIRS) || (symbol == SYM_GOLD);
}

Enemy* Floor::canPlayerAttack(string direction){
    Cell* cell = getNeighbourCell(direction, Player::getInstance());
    Enemy* enemy = dynamic_cast<Enemy*>(cell->getEntity());
    return enemy;
}

ItemDecorator* Floor::canPlayerTakePotion(string direction){
    Cell* cell = getNeighbourCell(direction, Player::getInstance());
    ItemDecorator* potion = dynamic_cast<ItemDecorator*>(cell->getEntity());
    if (potion && potion->getSymbol() == SYM_POTION){
        cell->setSymbol(SYM_TILE);
        cell->setEntity(nullptr);
        return potion;
    }
    return nullptr;
}

bool Floor::hasDragonGuardTreasure(DragonTreasure* gold){
    bool result = false;
    int x = gold->getX();
    int y = gold->getY();
    for(int i =-1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            Entity* item = cells[x+i][y+j]->getEntity();
            Dragon* dragon = dynamic_cast<Dragon*>(item);
            if(dragon){
                return true;
            } 
        }
    }
    return result;
}

void Floor::resetCurCell(Cell* cell, char symbol) {
    cell->setSymbol(symbol);
    cell->setEntity(nullptr);
}

vector<string> Floor::enemyTurn(){
    vector<string> msg;
    Player* p = Player::getInstance();
    for(int i = 0 ; i < MAX_ROW; i++){
        for(int j = 0; j < MAX_COLUMN; j++){
             Cell* current = cells[i][j];
             if(current->getChamberID() > -1){
                  Enemy* enemy = dynamic_cast<Enemy*>(current->getEntity());
                  if(enemy && !enemy->hasMoved()){
                    if (enemy->isDead()) {
                        Goblin* g = dynamic_cast<Goblin*>(p);
                        if (g) {
                            p->setGold(p->getGold() + 5);
                        }
                        string s = string(1, enemy->getSymbol()) + " was slain!";
                        msg.push_back(s);
                        Human* h = dynamic_cast<Human*>(enemy);
                        Merchant* m = dynamic_cast<Merchant*>(enemy);
                        if (h || m) {
                            Treasure* gold = new MerchantTreasure(p);
                            current->setSymbol(SYM_GOLD);
                            current->setEntity(gold);
                            gold->setX(current->getRow());
                            gold->setY(current->getCol());
                            gold->setSymbol(SYM_GOLD);
                        } else {
                            current->setSymbol(SYM_TILE);
                            current->setEntity(nullptr);
                            continue;
                        }
                    }
                    if (enemy->isPlayerInRange(p->getX(), p->getY())) {
                        Merchant* m = dynamic_cast<Merchant*>(current->getEntity());
                        if (!m || Merchant::isHostile()) {
                            int x = enemy->attackPlayer(p->getRace(), p->getDef());
                            string s = string(1, enemy->getSymbol());
                            if (x > 0) {
                                p->takeDamage(x);
                                // msg += " dealt " + std::to_string(enemy->calculateDamageToPlayer(p->getRace(), p->getDef())) 
                                //                     + " damage to player\n";

                                s += " dealt " + std::to_string(x) + " damage to player";
                            } else {
                                s += " missed";
                            }
                            msg.push_back(s);
                        }
                    } else {
                        Dragon* dragon = dynamic_cast<Dragon*>(enemy);
                        if(!dragon){
                            bool done = false;
                            while(!done){
                                int i = std::rand() % 8;
                                string dir = DIRECTIONS[i];
                                Cell* next = getNeighbourCell(dir, enemy);
                                if(!next->isOccupied() ){
                                    done = true;
                                    enemy->move(next);
                                    resetCurCell(current, SYM_TILE);
                                   
                                } 
                            }
                        }
                    }
                }
            }
        }
    }

    // reset back moved 
     for(int i = 0 ; i < MAX_ROW; i++){
        for(int j = 0; j < MAX_COLUMN; j++){
            Cell* current = cells[i][j];
            if(current->getChamberID() > -1){
                Enemy* enemy = dynamic_cast<Enemy*>(current->getEntity());
                if(enemy){
                    enemy->setMoved(false);
                }
            }
        }
     }
     return msg;      
}

string Floor::movePlayer(string dir){
    string msg = "";
    Player* player = Player::getInstance();
    Cell* nextCell = getNeighbourCell(dir, player);

    if(canMovePlayer(nextCell)){
        if(nextCell->getSymbol() == SYM_GOLD){
            bool pickUpGold = canPlayerPickUpGold(nextCell);
            if(pickUpGold){
                resetCurCell(cells[player->getX()][player->getY()], player->getCellSymbol());
                player->move(nextCell, canPlayerPickUpGold(nextCell));
                msg = "PC move to : " + directionMap[dir] + " | player pick up gold\n";
            }
        }else{
            resetCurCell(cells[player->getX()][player->getY()], player->getCellSymbol());
            player->move(nextCell, false);
            msg = "PC move to: " + directionMap[dir];
            if(hasUnknownPotion(nextCell)) {
                msg += " and see an unknown potion";
            }
            msg += "\n";
        }
    }
    return msg;
}

bool Floor::hasUnknownPotion(Cell* cell){
    for( string s : DIRECTIONS){
        Cell* next = getNextCellWithDirection(s, cell->getRow(), cell->getCol());
        if(next){
            Entity* e = next->getEntity();
            Potion* potion = dynamic_cast<Potion*>(e);
            if(potion){
                return true;
            }
        }
    }
    return false;
}

bool Floor::canPlayerPickUpGold(Cell* cell) {
    bool result = false;
    if(cell->getSymbol() == SYM_GOLD){
        Entity* entity = cell->getEntity();
        DragonTreasure* treasure = dynamic_cast<DragonTreasure*>(entity);
        return treasure ? !hasDragonGuardTreasure(treasure) :  true;
    }
    return result;
}

Cell* Floor::getNeighbourCell(string dir, Entity* entity){
    int nextRow = entity->getX();
    int nextCol = entity->getY();
    return getNextCellWithDirection(dir, nextRow, nextCol);
    // if ( dir == NORTH){
    //     nextRow--;
    // } else if ( dir == SOUTH){
    //     nextRow++;
    // } else if ( dir == EAST) {
    //     nextCol++;
    // } else if ( dir == WEST) {
    //     nextCol--;
    // } else if ( dir == NORTH_EAST) {
    //     nextRow--;
    //     nextCol++;
    // } else if ( dir == NORTH_WEST ) {
    //     nextRow--;
    //     nextCol--;
    // } else if ( dir == SOUTH_EAST ) {
    //     nextRow++;
    //     nextCol++;
    // } else if ( dir == SOUTH_WEST ) {
    //     nextRow++;
    //     nextCol--;
    // }
    // return cells[nextRow][nextCol];
}

Cell* Floor::getNextCellWithDirection(string dir, int nextRow, int nextCol){
    if ( dir == NORTH){
        nextRow--;
    } else if ( dir == SOUTH){
        nextRow++;
    } else if ( dir == EAST) {
        nextCol++;
    } else if ( dir == WEST) {
        nextCol--;
    } else if ( dir == NORTH_EAST) {
        nextRow--;
        nextCol++;
    } else if ( dir == NORTH_WEST ) {
        nextRow--;
        nextCol--;
    } else if ( dir == SOUTH_EAST ) {
        nextRow++;
        nextCol++;
    } else if ( dir == SOUTH_WEST ) {
        nextRow++;
        nextCol--;
    }
    return cells[nextRow][nextCol];
}



