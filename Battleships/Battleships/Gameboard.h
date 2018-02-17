#pragma once
#include "Ship.h"
#include <string>
using std::string;

static const int SHIP_COUNT = 4;
static const int SHIPS_IN_GAME[] = { 1,1,1,1 };  // number of ships of each size 5, 4, 3, 2

enum Direction { North, East, South, West };

class Gameboard
{
public:
	Gameboard(int boardSize);
	~Gameboard();

	void addShip(int shipSize, int shipIndex, string coord, string dir);
	void printShots();
	void printShips();
	
	
	bool parseCoordinates(int& x, int& y, string input);

private:

	//list of all ships that have been added to the gameboard
	Ship shiplist[SHIP_COUNT];

	int boardSize_;
	char **shots_;
	int ** ships_;


	//helper functions for printing game boards
	void printHeader();
	void printFooter();

	//Function that parses user input into coordinates on the game board

};

