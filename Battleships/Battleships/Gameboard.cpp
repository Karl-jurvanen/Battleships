#include "Gameboard.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


Gameboard::Gameboard(int boardSize):boardSize_(boardSize)
{

	shots_ = new char*[boardSize_];
	ships_ = new int*[boardSize_];

	for (size_t i = 0; i < boardSize_; i++)
	{
		shots_[i] = new char[boardSize_];
		ships_[i] = new int[boardSize_];
	}


	//Initialize both gameboards to empty
	for (size_t i = 0; i < boardSize_; i++)
	{
		for (size_t j = 0; j < boardSize_; j++)
		{
			shots_[i][j] = 0;
			ships_[i][j] = 0;
		}
	}


	shots_[2][3] = '#';
}


Gameboard::~Gameboard()
{
	for (size_t i = 0; i < boardSize_; i++)
	{
		delete[] shots_[i];
		delete[] ships_[i];
	}
	delete[] shots_;
	delete[] ships_;


	cout << "Gameboard destructor." << endl;
}

void Gameboard::addShip(int shipSize, int shipIndex)
{

}

void Gameboard::printShots()
{
	char column = 'A';

	
	//Print header for table
	cout << "    ";
	for (size_t i = 1; i <= boardSize_; i++)
	{
		cout << i << " ";
	}

	cout << endl << "  ";

	for (size_t i = 0; i < boardSize_ * 2 + 4; i++)
	{
		cout << "-";
	}
	cout << endl;

	// Print the table with row letters
	for (size_t i = 0; i < boardSize_; i++)
	{

		cout << column << " | ";
		for (size_t j = 0; j < boardSize_; j++)
		{

			cout << shots_[i][j] << " ";
		}

		cout << " | " << column << endl;
		column++;	//incrementing a char type moves the character to next in the alphabet
	}
	//Print footer for the table 

	cout << "  ";
	for (size_t i = 0; i < boardSize_ * 2 + 4; i++)
	{
		cout << "-";
	}

	cout << endl << "    ";
	for (size_t i = 1; i <= boardSize_; i++)
	{
		cout << i << " ";
	}
	cout << endl;
}

