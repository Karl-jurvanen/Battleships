#pragma once
#include "Ship.h"
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
	void printShips();

private:

	//list of all ships that have been added to the gameboard
	Ship shiplist[SHIP_COUNT];

	int boardSize_;
	char **shots_;
	int ** ships_;


	//helper functions for printing game boards
	void printHeader();
	void printFooter();

};

