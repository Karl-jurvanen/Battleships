#include "Gameboard.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


Gameboard::Gameboard()
{

}


Gameboard::~Gameboard()
{
}

void Gameboard::addShip()
{
}

void Gameboard::printShots(char taulukko[BOARD_SIZE][BOARD_SIZE], size_t elems)
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

			cout << taulukko[i][j] << " ";
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

