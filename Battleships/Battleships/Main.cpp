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
	int game = 13;

	Gameboard game2(10);


	int x;
	int y;
	
	if (game2.parseCoordinates(x, y, "A10"))
	{
	cout << x << " " << y << endl;

	}


	system("pause");
}