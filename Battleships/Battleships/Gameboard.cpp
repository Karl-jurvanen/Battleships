#include "Gameboard.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


Gameboard::Gameboard(int boardSize):boardSize_(boardSize)
{

	shots_ = new char*[boardSize_];
	ships_ = new int*[boardSize_];

	for (int i = 0; i < boardSize_; i++)
	{
		shots_[i] = new char[boardSize_];
		ships_[i] = new int[boardSize_];
	}


	//Initialize both gameboards to empty
	for (int i = 0; i < boardSize_; i++)
	{
		for (int j = 0; j < boardSize_; j++)
		{
			shots_[i][j] = 0;
			ships_[i][j] = -1;
		}
	}

}


Gameboard::~Gameboard()
{
	for (int i = 0; i < boardSize_; i++)
	{
		delete[] shots_[i];
		delete[] ships_[i];
	}
	delete[] shots_;
	delete[] ships_;


	cout << "Gameboard destructor." << endl;
}

char ** Gameboard::getShots() const
{
	return shots_;
}

int ** Gameboard::getShips() const
{
	return ships_;
}

int Gameboard::getBoardSize() const
{
	return boardSize_;
}

bool Gameboard::addShip(size_t shipSize, int shipsAdded, string coord, string dir)
{
	int x;
	int y;
	if (parseCoordinates(x,y,coord))
	{

		if (dir == "p")
		{
			for (size_t i = 0; i < shipSize; i++)
			{
				if (! checkCoordinate(x, (y-i)))
				{
					cout << "Ship goes off game board." << endl;
					return false;
				}
				if (ships_[y - i][x] != -1)
				{
					cout << "Ship already there." << endl;
					return false;
				}
				
			}
			shiplist[shipsAdded].setSize(shipSize);
			for (size_t i = 0; i < shipSize; i++)
			{
				ships_[y-i][x] = shipsAdded;
			}
			return true;
			
		}

		else if (dir == "i")
		{
			for (size_t i = 0; i < shipSize; i++)
			{
				if (!checkCoordinate( (x +i), y))
				{
					cout << "Ship goes off game board." << endl;
					return false;
				}
				if (ships_[y][x+i] != -1)
				{
					cout << "Ship already there." << endl;
					return false;
				}

			}
			shiplist[shipsAdded].setSize(shipSize);
			for (size_t i = 0; i < shipSize; i++)
			{
				ships_[y][x +i] = shipsAdded;
			}
			return true;
		}

		else if (dir == "e")
		{
			for (size_t i = 0; i < shipSize; i++)
			{
				if (!checkCoordinate(x, (y + i)))
				{
					cout << "Ship goes off game board." << endl;
					return false;
				}
				if (ships_[y + i][x] != -1)
				{
					cout << "Ship already there." << endl;
					return false;
				}

			}
			shiplist[shipsAdded].setSize(shipSize);
			for (size_t i = 0; i < shipSize; i++)
			{
				ships_[y + i][x] = shipsAdded;
			}
			return true;
		}

		else if (dir == "l")
		{
			for (size_t i = 0; i < shipSize; i++)
			{
				if (!checkCoordinate( (x-i), y))
				{
					cout << "Ship goes off game board." << endl;
					return false;
				}
				if (ships_[y][x-i] != -1)
				{
					cout << "Ship already there." << endl;
					return false;
				}

			}
			shiplist[shipsAdded].setSize(shipSize);
			for (size_t i = 0; i < shipSize; i++)
			{
				ships_[y][x-i] = shipsAdded;
			}
			return true;
		}
		else
		{
			cout << "Virheellinen suunta." << endl;
			return false;
		}
	}
	return false;
}

void Gameboard::printShots()
{

	printHeader();

	char column = 'A';

	// Print the game board with row letters on both sides
	for (int i = 0; i < boardSize_; i++)
	{
		cout << column << " | ";
		for (int j = 0; j < boardSize_; j++)
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
	for (int y = 0; y < boardSize_; y++)
	{
		cout << column << " | ";
		for (int x = 0; x < boardSize_; x++)
		{
			if (ships_[y][x] == -1)
			{
				cout << "  ";
			}
			else
			{
				
				cout << shiplist[ships_[y][x]].getSize() << " ";
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
	for (int i = 1; i <= boardSize_; i++)
	{
		cout << i << " ";
	}

	cout << endl << "  ";

	for (int i = 0; i < boardSize_ * 2 + 4; i++)
	{
		cout << "-";
	}
	cout << endl;
}

//Function that prints the bottom rows of gameboard
void Gameboard::printFooter()
{
	cout << "  ";
	for (int i = 0; i < boardSize_ * 2 + 4; i++)
	{
		cout << "-";
	}

	cout << endl << "    ";
	for (int i = 1; i <= boardSize_; i++)
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
		y = toupper(input[0]) - 'A';
		try
		{
		x = stoi(input.substr(1)) - 1;

		}
		catch (const std::invalid_argument&)
		{
			cout << "Virheellinen syote." << endl;
			return false;
		}
		
		if (! checkCoordinate(x,y) )
		{
			//one of the coordinates is outside of the game board
			cout << "Virheellinen koordinaatti." << endl;
			return false;
		}
	
		return true;
}

//Function returns true if coordinate is within the gameboard
bool Gameboard::checkCoordinate(int x, int y)
{

	return  ((x >= 0 && y >= 0) && (x < boardSize_ && y < boardSize_));
}

