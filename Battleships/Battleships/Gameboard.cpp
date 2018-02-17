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
			ships_[i][j] = -1;
		}
	}


	shots_[2][3] = '#';
	ships_[4][1] = 3;
	ships_[4][2] = 3;
	ships_[4][3] = 3;
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

void Gameboard::addShip(int shipSize, int shipIndex, string coord, string dir)
{
	
}

void Gameboard::printShots()
{

	printHeader();

	char column = 'A';

	// Print the game board with row letters on both sides
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

	printFooter();


}

void Gameboard::printShips()
{
	printHeader();

	char column = 'A';

	// Print the game board with row letters on both sides
	for (size_t i = 0; i < boardSize_; i++)
	{
		cout << column << " | ";
		for (size_t j = 0; j < boardSize_; j++)
		{
			if (ships_[i][j] == -1)
			{
				cout << "  ";
			}
			else
			{
				cout << ships_[i][j] << " ";
			}
		}

		cout << " | " << column << endl;
		column++;	
	}

	printFooter();
}

//Function that prints the top rows of gameboard
void Gameboard::printHeader()
{
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
}

//Function that prints the bottom rows of gameboard
void Gameboard::printFooter()
{
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

bool Gameboard::parseCoordinates(int& x, int& y, string input)
{

	//check if input is not right length
	
	if (input.length() < 2 || input.length() > 3)
	{
		return false;
	}
		x = toupper(input[0]) - 'A';
		try
		{
		y = stoi(input.substr(1)) - 1;

		}
		catch (const std::invalid_argument&)
		{
			cout << "Virheellinen syote." << endl;
			return false;
		}
		
		if ( (x < 0 || y < 0) || (x >= boardSize_ || y >= boardSize_) )
		{
			//one of the coordinates is outside of the game board
			cout << "Virheellinen koordinaatti." << endl;
			return false;
		}
	
		return true;
}

