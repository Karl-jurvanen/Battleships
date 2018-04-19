#pragma once
#include "Ship.h"
#include <string>
using std::string;

static const int SHIPS_IN_GAME[] = { 1,1,1,1 };  // number of ships of each size 5, 4, 3, 2

const string SHIP_ALREADY_THERE = "Ship already there.\n\n";
const string SHIP_OUT_OF_BOUNDS = "Ship goes off game board.\n\n";
const string BAD_COORDINATE = "Virheellinen koordinaatti.\n\n";
const string BAD_INPUT = "Virheellinen syote\n";
const string ALREADY_SHOT_THERE = "Kohtaan  on jo ammuttu.\n\n";
const string MISSED_SHIP = "\nLaukaus kohtaan  ei osunut.\n\n";
const string HIT_SHIP = "\nLaukaus kohtaan  osui laivaan.\n\n";
const string SUNK_SHIP = "\nLaukaus kohtaan  upotti laivan.\n\n";

class Gameboard
{
public:
	Gameboard();
	Gameboard(int boardSize, int shipCount);
	~Gameboard();

	char ** getShots() const;
	int ** getShips()const;
	int getBoardSize()const;

	void initialize();
	bool addShip(size_t shipSize,  string coord, string dir);
	bool addShip(size_t shipSize, int x, int y, string dir);
	bool addShipQuiet(size_t shipSize, int x, int y, string dir);
	bool shoot(string coord);
	void sinkShip(int shipIndes);
	void printShots() const;
	void printShips() const;
	
	bool checkGameOver()const;
	
private:

	//list of all ships that have been added to the gameboard
	Ship * shiplist_;

	int shipCount_;
	int shipsSunk_;
	int shipsAdded_;
	int boardSize_;
	char **shots_;
	int ** ships_;


	//helper functions for printing game boards
	void printHeader() const;
	void printFooter() const;

	//Function that parses user input into coordinates on the game board
	bool parseCoordinates(int& x, int& y, string input) const;
	
	//Function that checks if given coordinate is valid
	bool checkCoordinate(int x, int y) const;

};

