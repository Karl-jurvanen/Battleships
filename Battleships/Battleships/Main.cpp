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
	game2.addShip(5, "G6", "p");
	game2.addShip(4, "G5", "l");
	game2.addShip(4, "A1", "e");
	game2.addShip(3, "A4", "e");
	game2.printShips();
   
	game2.shoot("A1");
	game2.shoot("A1");
	game2.shoot("B2");
	game2.shoot("G6");

	game2.shoot("A1");
	game2.shoot("b1");
	game2.shoot("c1");
	game2.shoot("d1");
	game2.shoot("e1");


	game2.printShots();
	system("pause");
}