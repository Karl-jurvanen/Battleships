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
	Gameboard game2(10);

	game2.printShips();
	game2.addShip(5, 2, "A6", "p");
	game2.printShips();
	system("pause");
}