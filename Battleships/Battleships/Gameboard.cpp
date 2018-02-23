#include "Gameboard.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


Gameboard::Gameboard(int boardSize) :boardSize_(boardSize), shipsAdded_(0)
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

bool Gameboard::addShip(size_t shipSize,  string coord, string dir)
{
	int x;
	int y;
	if (parseCoordinates(x, y, coord))
	{

		if (dir == "p")
		{
			for (size_t i = 0; i < shipSize; i++)
			{
				if (!checkCoordinate(x, (y - i)))
				{
					cout << "Ship goes off game board." << endl;
					return false;
				}
				if (ships_[x][y-i] != -1)
				{
					cout << "Ship already there." << endl;
					return false;
				}

			}
			shiplist[shipsAdded_].setSize(shipSize);
			for (size_t i = 0; i < shipSize; i++)
			{
				ships_[x][y-i] = shipsAdded_;
			}
			shipsAdded_++;
			return true;

		}

		else if (dir == "i")
		{
			for (size_t i = 0; i < shipSize; i++)
			{
				if (!checkCoordinate((x + i), y))
				{
					cout << "Ship goes off game board." << endl;
					return false;
				}
				if (ships_[x+i][y] != -1)
				{
					cout << "Ship already there." << endl;
					return false;
				}

			}
			shiplist[shipsAdded_].setSize(shipSize);
			for (size_t i = 0; i < shipSize; i++)
			{
				ships_[x+i][y] = shipsAdded_;
			}
			shipsAdded_++;
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
				if (ships_[x][y+i] != -1)
				{
					cout << "Ship already there." << endl;
					return false;
				}

			}
			shiplist[shipsAdded_].setSize(shipSize);
			for (size_t i = 0; i < shipSize; i++)
			{
				ships_[x][y+i] = shipsAdded_;
			}
			shipsAdded_++;
			return true;
		}

		else if (dir == "l")
		{
			for (size_t i = 0; i < shipSize; i++)
			{
				if (!checkCoordinate((x - i), y))
				{
					cout << "Ship goes off game board." << endl;
					return false;
				}
				if (ships_[x-i][y] != -1)
				{
					cout << "Ship already there." << endl;
					return false;
				}

			}
			shiplist[shipsAdded_].setSize(shipSize);
			for (size_t i = 0; i < shipSize; i++)
			{
				ships_[x-i][y] = shipsAdded_;
			}
			shipsAdded_++;
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

bool Gameboard::shoot(string coord)
{
	int x;
	int y;
	if (parseCoordinates(x, y, coord))
	{
		//check if we the coordinate has already been shot at
		if (shots_[x][y] != 0)
		{
			cout << coord << " | Already shot there." << endl;
			return false;
		}
		else
		{
			//Check if there is ship there
			if (ships_[x][y] == -1)
			{
				cout << coord <<  " | Miss." << endl;
				shots_[y][x] = 'X';
				return true;
			}
			else
			{
				
				int target = ships_[x][y];
				shiplist[target].hit();
				//Check if the target that was hit sinks 
				if (shiplist[target].getHits() == shiplist[target].getSize())
				{
					cout << coord << " | Ship sunk" << endl;
					sinkShip(target);
				}
				else
					//Ship was hit but it did not sink
				{
					cout << coord << " | Hit" << endl;
					shots_[x][y] = '*';
				}
				return true;
			}
		}
	}
	return false;
}

void Gameboard::sinkShip(int shipIndes)
{
	//Loop through shots_ and change value to # where ships_ == shipindex
	
	for (int y = 0; y < boardSize_; y++)
	{
		for (int x = 0; x < boardSize_; x++)
		{
			if (ships_[x][y] == shipIndes)
			{
				shots_[x][y] = '#';
			}
		}
	}

}

void Gameboard::printShots()
{

	printHeader();

	char column = 'A';

	// Print the game board with row letters on both sides
	for (int j = 0; j < boardSize_; j++)
	{
		cout << column << " | ";
		for (int i = 0; i < boardSize_; i++)
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
			if (ships_[x][y] == -1)
			{
				cout << "  ";
			}
			else
			{
				cout << shiplist[ships_[x][y]].getSize() << " ";
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
	//First character of input corresponds to y coordinate and 
	//second and trird to x-coordinate

	y = toupper(input[0]) - 'A';
	try
	{
		x = stoi(input.substr(1)) - 1;

	}
	catch (const std::invalid_argument&)
	{
		//catch possible exception from converting the string to int
		cout << "Virheellinen syote." << endl;
		return false;
	}

	if (!checkCoordinate(x, y))
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

