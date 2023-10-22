#ifndef ___FLOOR_H___
#define ___FLOOR_H___
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iostream>
#include <map>
#include "cell.h"
#include "chamber.h"
#include "../constants.h"
#include "../players/player.h"
#include "../items/itemDecorator.h"
#include "../enemies/dragon.h"
#include "../enemies/merchant.h"
#include "../enemies/human.h"
#include "../players/goblin.h"
#include "../items/treasure.h"
#include "../items/merchantHoard.h"

class Chamber;

class Floor {

	public:
		Floor();
		~Floor();
		void loadFromFile(std::ifstream *floorStream);
		void displayFloor(string actionMsg, int level);
        Cell *getCell(int i, int j);
		void spawnFloor();
		void spawnPlayers();
		string movePlayer(string direction);
		vector<string> enemyTurn();
		Enemy* canPlayerAttack(string direction);
		ItemDecorator* canPlayerTakePotion(string direction);
		
	private:
		int locateChamber(int i, int j);
		Cell* cells[MAX_ROW][MAX_COLUMN];
		Chamber* chambers[MAX_CHAMBERS];
		map<char, string> colorMap = {	{SYM_PLAYER, ANSI_BLUE}, {SYM_STAIRS, ANSI_BLUE}, {SYM_GOLD, ANSI_YELLOW},
										{SYM_POTION, ANSI_GREEN},  {ENEMY_MERCHANT, ANSI_RED}, {ENEMY_DRAGON, ANSI_RED},
										{ENEMY_DWARF, ANSI_RED}, {ENEMY_ELF, ANSI_RED}, {ENEMY_HUMAN, ANSI_RED}, 
										{ENEMY_ORC, ANSI_RED}, {ENEMY_HALFING, ANSI_RED}};

		void spawnEnemies();
		void spawnPotions();
		void spawnTreasures();
		void spawnStairs();
		bool canMovePlayer(Cell* cell);
		void resetCurCell(Cell* cell, char symbol);
		Chamber *getRandomChamber();
		Cell* getNeighbourCell(string direction, Entity* entity);
		bool hasDragonGuardTreasure(DragonTreasure* gold);
		bool canPlayerPickUpGold(Cell* cell);
		bool isValidSymbol(char s);
		bool hasUnknownPotion(Cell* cell);
		Cell* getNextCellWithDirection(string dir, int nextRow, int nextCol);

};
#endif
