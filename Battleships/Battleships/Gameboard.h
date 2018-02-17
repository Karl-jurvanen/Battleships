#pragma once
#include "Ship.h"
static const int BOARD_SIZE = 10;
static const int SHIP_COUNT = 4;
static const int SHIPS_IN_GAME[] = { 1,1,1,1 };  // number of ships of each size 5, 4, 3, 2

enum Direction { North, East, South, West };

class Gameboard
{
public:
	Gameboard(int boardSize);
	~Gameboard();

	void addShip(int shipSize, int shipIndex);
	void printShots();

private:

	//list of all ships that have been added to the gameboard
	Ship shiplist[SHIP_COUNT];

	int boardSize_;
	char **ary;
	char shots_[BOARD_SIZE][BOARD_SIZE];
	int ships_[BOARD_SIZE][BOARD_SIZE];

};

