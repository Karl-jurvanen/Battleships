#pragma once
#include "Ship.h"
#include <string>
using std::string;

static const int SHIPS_IN_GAME[] = { 1,1,1,1 };  // number of ships of each size 5, 4, 3, 2

const string SHIP_ALREADY_THERE = "Koordinaatissa on jo laiva.\n\n";
const string SHIP_OUT_OF_BOUNDS = "Laiva menee pelilaudan ulkopuolelle.\n\n";
const string BAD_COORDINATE = "Virheellinen koordinaatti.\n\n";
const string BAD_DIRECTION = "Virheellinen suunta.\n\n";
const string BAD_INPUT = "\nVirheellinen syote\n";
const string ALREADY_SHOT_THERE = "\nKohtaan  on jo ammuttu.\n\n";
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
	int ** getShips() const;
	int ** getValues() const;
	int getBoardSize()const;

	void initialize();
	int addShip(int shipSize,  string coord, string dir);
	int addShip(int shipSize, int x, int y, string dir);
	bool shoot(string coord, string& message);
	int shoot(int x, int y);
	void sinkShip(int shipIndex);
	void printShots() const;
	void printShips() const;

	//functions used by shooting AI to find best target
	int** calculateValues();
	void getBestTarget(int& x, int& y);
	
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
	int ** values_;

	//helper functions for printing game boards
	void printHeader() const;
	void printFooter() const;

	//Function that parses user input into coordinates on the game board
	bool parseCoordinates(int& x, int& y, string input) const;
	
	//Function that checks if given coordinate is valid
	bool checkCoordinate(int x, int y) const;

	//function for getting value for coordinate based on neighbors
	int checkNeighbors(int x, int y);
	int getNeighborValue(int x, int y);

};

