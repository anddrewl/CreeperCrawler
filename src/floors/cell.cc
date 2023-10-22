#include "cell.h"

Cell::Cell(int i, int j, char s) : row(i), col(j), symbol(s){}
Cell::~Cell(){
    delete entity;
}

char Cell::getSymbol(){
    return symbol;
}

void Cell::setSymbol(char sb){
    symbol = sb;
}

Cell::CellType Cell::getCellType(){
    return cellType;
}

void Cell::setCellType(Cell::CellType ct){
    cellType = ct;
}

int Cell::getRow(){
    return row;
}

void Cell::setRow(int r){
    row = r;
}

int Cell::getCol() {
    return col;
}

bool Cell::isOccupied(){
    return symbol != SYM_TILE;
}

int Cell::getChamberID(){
    return chamberID;
}

void Cell::setChamberID(int id){
    chamberID = id;
}

bool Cell::isWalkable(){
    return true;
}

void Cell::setEntity(Entity* en) {
    entity = en;
}
 
Entity* Cell::getEntity() {
    return entity;
}
