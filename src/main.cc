#include <iostream>
#include "chamberCrawler.h"
using namespace std;

// a comment

int main(int argc, char* argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    ChamberCrawler *game = new ChamberCrawler();
    if(argc > 1){
        game->start(argv[1], true);
    }else{
         game->start("", true);
    }
    delete game;
}
