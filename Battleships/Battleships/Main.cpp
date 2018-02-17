#include "Gameboard.h"
#include "Ship.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;



void test(int board)
{
	Gameboard game1(board);
	game1.printShots();
	game1.printShips();
}

int main()
{
	Gameboard game2(7);

	game2.printShips();
	game2.addShip(5, 1, "G6", "p");
	game2.addShip(4, 2, "G5", "l");
	game2.addShip(4, 2, "A1", "e");
	game2.addShip(3, 3, "A4", "e");
	game2.printShips();
	system("pause");
}