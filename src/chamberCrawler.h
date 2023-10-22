#ifndef ___CHAMBERCRAWLER_H___
#define ___CHAMBERCRAWLER_H___

#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "./floors/floor.h"
#include "./players/player.h"
#include "./players/troll.h"
#include "./enemies/merchant.h"

using namespace std;

class ChamberCrawler {
	private:
		string floorLayoutFile;
		ifstream *floorStream;
		void play();
		string playerTakeTurn();
		string enemiesTakeTurn();
		string processPlayerAttackCmd(string direction);
		string processPlayerUsePotionCmd(string direction);
		void restartOrQuit();
		void goToNextFloor();
		void restartGame();
		bool isValidCmd(string cmd);
		bool isDefaultFloor;
		bool nextFloor;
		bool quit;
		bool restart;
		bool canEnemyTakeTurn;
		int level;
		Floor* floor;

	public:
		ChamberCrawler();
		~ChamberCrawler();
		void setGameRace();
		void start(string floorFile, bool ignoreSetRace);
		void loadFloor();
};
#endif
