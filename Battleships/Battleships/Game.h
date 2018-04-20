#pragma once
#include "Gameboard.h"
#include <string>
using std::string;

const string ADD_SHIP_START = "Anna  pituisen laivan alkupiste: ";
const string ADD_SHIP_DIR = "Anna suunta (p(ohjoinen) / i(ta) / e(tela) / l(ansi)): ";
const string SHOOT_COORD = "Anna ampumiskoordinaatit: ";
const string SHIPS_NOT_SET = "Syota laivat ennen ampumista.\n";

class Game
{
public:
	Game();
	Game(int boardsize, int shipList[], int shipSizes, int shipCount);
	~Game();
	
	void addShips();
	void addShipsRandom();
	void shoot();
	void shootRandom();
	void shootAI();
	void menu();

private:
	Gameboard board_;
	int shipCount_;
	int * shipList_;
	int shipSizes_; // number of different ship sizes in shipList_

	int gameOver_;
};