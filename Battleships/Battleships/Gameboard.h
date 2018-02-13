#pragma once
#include "Ship.h"
static const int BOARD_SIZE = 7;
static const int SHIP_COUNT = 4;
static const int SHIPS_IN_GAME[] = { 1,1,1,1 };  // number of ships of each size 5, 4, 3, 2

enum Direction { North, East, South, West };

class Gameboard
{
public:
	Gameboard();
	~Gameboard();

	void addShip();
	void printShots(char taulukko[BOARD_SIZE][BOARD_SIZE], size_t elems);

private:

	Ship shiplist[SHIP_COUNT];

	char shots_[BOARD_SIZE][BOARD_SIZE];
	int ships_[BOARD_SIZE][BOARD_SIZE];

};

