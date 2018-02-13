#include "Gameboard.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


Gameboard::Gameboard():elems(BOARD_SIZE)
{
	//Initialize both gameboards to empty
	for (size_t i = 0; i < BOARD_SIZE; i++)
	{
		for (size_t j = 0; j < BOARD_SIZE; j++)
		{
			shots_[i][j] = 0;
			ships_[i][j] = 0;
		}
	}

	shots_[2][3] = '#';

}


Gameboard::~Gameboard()
{
}

void Gameboard::addShip(int shipSize, int shipIndex)
{

}

void Gameboard::printShots()
{
	char column = 'A';

	
	//Print header for table
	cout << "    ";
	for (size_t i = 1; i <= elems; i++)
	{
		cout << i << " ";
	}

	cout << endl << "  ";

	for (size_t i = 0; i < BOARD_SIZE * 2 + 4; i++)
	{
		cout << "-";
	}
	cout << endl;

	// Print the table with row letters
	for (size_t i = 0; i < elems; i++)
	{

		cout << column << " | ";
		for (size_t j = 0; j < elems; j++)
		{

			cout << shots_[i][j] << " ";
		}

		cout << " | " << column << endl;
		column++;	//incrementing a char type moves the character to next in the alphabet
	}
	//Print footer for the table 

	cout << "  ";
	for (size_t i = 0; i < BOARD_SIZE * 2 + 4; i++)
	{
		cout << "-";
	}

	cout << endl << "    ";
	for (size_t i = 1; i <= elems; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}

