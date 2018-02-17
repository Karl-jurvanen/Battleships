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
}

int main()
{
	int game = 20;

	for (int i = 10; i < game; i++)
	{
		test(game);
	}
	

	system("pause");
}