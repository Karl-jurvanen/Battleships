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
	int game = 13;

	for (int i = 7; i < game; i++)
	{
	}
	
		test(7);

	system("pause");
}