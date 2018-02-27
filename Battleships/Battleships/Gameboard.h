#pragma once
#include "Ship.h"
#include <string>
using std::string;

static const int SHIPS_IN_GAME[] = { 1,1,1,1 };  // number of ships of each size 5, 4, 3, 2

const string SHIP_ALREADY_THERE = "Ship already there.\n";
const string SHIP_OUT_OF_BOUNDS = "Ship goes off game board.\n";
const string BAD_COORDINATE = "Virheellinen koordinaatti.\n";
const string BAD_INPUT = "Virheellinen syote\n";
const string ALREADY_SHOT_THERE = "Kohtaan  on jo ammuttu.\n";
const string MISSED_SHIP = "Laukaus kohtaan  ei osunut.\n";
const string HIT_SHIP = "Laukaus kohtaan  osui laivaan.\n";
const string SUNK_SHIP = "Laukaus kohtaan  upotti laivan.\n";

enum Direction { North, East, South, West };

class Gameboard
{
public:
	Gameboard(int boardSize, int shipCount);
	Gameboard();
	~Gameboard();

	char ** getShots() const;
	int ** getShips()const;
	int getBoardSize()const;

	void initialize();
	bool addShip(size_t shipSize,  string coord, string dir);
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
	bool checkCoordinate(int x, int y) const;

};

