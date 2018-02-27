#include "Gameboard.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;


Gameboard::Gameboard(int boardSize, int shipCount) :boardSize_(boardSize), shipCount_(shipCount), shipsAdded_(0), shipsSunk_(0)
{
	shiplist_ = new Ship[shipCount_];

	shots_ = new char*[boardSize_];
	ships_ = new int*[boardSize_];

	for (int i = 0; i < boardSize_; i++)
	{
		shots_[i] = new char[boardSize_];
		ships_[i] = new int[boardSize_];
	}

	//Initialize both gameboards to empty
	initialize();
}

Gameboard::Gameboard():boardSize_(7), shipCount_(4), shipsAdded_(0), shipsSunk_(0)
{
	shiplist_ = new Ship[shipCount_];

	shots_ = new char*[boardSize_];
	ships_ = new int*[boardSize_];

	for (int i = 0; i < boardSize_; i++)
	{
		shots_[i] = new char[boardSize_];
		ships_[i] = new int[boardSize_];
	}
	initialize();
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
	delete[] shiplist_;

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

//Initialize the gameboards to empty state
void Gameboard::initialize()
{
	for (int i = 0; i < boardSize_; i++)
	{
		for (int j = 0; j < boardSize_; j++)
		{
			shots_[i][j] = 0;
			ships_[i][j] = -1;
			
		}
	}
	shipsAdded_ = 0;
	for (int i = 0; i < shipCount_; i++)
	{
		shiplist_[i] = Ship();	
	}
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
					cout << SHIP_OUT_OF_BOUNDS ;
					return false;
				}
				if (ships_[x][y-i] != -1)
				{
					cout << SHIP_ALREADY_THERE ;
					return false;
				}

			}
			shiplist_[shipsAdded_].setSize(shipSize);
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
					cout << SHIP_OUT_OF_BOUNDS ;
					return false;
				}
				if (ships_[x+i][y] != -1)
				{
					cout << SHIP_ALREADY_THERE;
					return false;
				}

			}
			shiplist_[shipsAdded_].setSize(shipSize);
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
					cout << SHIP_OUT_OF_BOUNDS ;
					return false;
				}
				if (ships_[x][y+i] != -1)
				{
					cout << SHIP_ALREADY_THERE ;
					return false;
				}

			}
			shiplist_[shipsAdded_].setSize(shipSize);
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
					cout << SHIP_OUT_OF_BOUNDS << endl;
					return false;
				}
				if (ships_[x-i][y] != -1)
				{
					cout << SHIP_ALREADY_THERE << endl;
					return false;
				}

			}
			shiplist_[shipsAdded_].setSize(shipSize);
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

//Shoot function retuens true if shooting is succesfull (hit or miss)
//and returns false if shooting failed (illegal coordinate or shooting in the same spot again)
bool Gameboard::shoot(string coord)
{
	int x;
	int y;
	string output;
	if (parseCoordinates(x, y, coord))
	{
		//check if we the coordinate has already been shot at
		if (shots_[x][y] != 0)
		{
			output = ALREADY_SHOT_THERE;
			cout << output.insert(8, coord) << endl;
			return false;
		}
		else
		{
			//Check if there is ship there
			if (ships_[x][y] == -1)
			{
				output = MISSED_SHIP;
				cout << output.insert(16, coord);
				shots_[x][y] = 'X';
				return true;
			}
			else
			{
				
				int target = ships_[x][y];
				shiplist_[target].hit();
				//Check if the target that was hit sinks 
				if (shiplist_[target].getHits() == shiplist_[target].getSize())
				{
					output = SUNK_SHIP;
					cout << output.insert(17, coord) ;
					sinkShip(target);
				}
				else
					//Ship was hit but it did not sink
				{
					output = HIT_SHIP;
					cout << output.insert(17, coord);
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
	shipsSunk_++;

}

void Gameboard::printShots() const
{
	cout << "Pelitilanne on seuraava:\n\n";
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

void Gameboard::printShips() const
{
	cout << "Laivat sijaitsevat seuraavissa paikoissa:\n\n";
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
				//print shipnumbers
				//cout << ships_[x][y] << " ";

				//print ship sizes
				cout << shiplist_[ships_[x][y]].getSize() << " ";
			}
		}

		cout << " | " << column << endl;
		column++;
	}

	printFooter();
}

bool Gameboard::checkGameOver() const
{
	if (shipsSunk_ == shipCount_)
	{
		//all ships have been sunk, end game
		return true;
	}
	else
	{
		return false;
	}
}

//Function that prints the top rows of gameboard
void Gameboard::printHeader() const
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
void Gameboard::printFooter() const
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

bool Gameboard::parseCoordinates(int& x, int& y, string input) const
{

	//check if input is not right length

	if (input.length() < 2 || input.length() > 3)
	{
		cout << BAD_INPUT;
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
		cout << BAD_INPUT;
		return false;
	}

	if (!checkCoordinate(x, y))
	{
		//one of the coordinates is outside of the game board
		cout << BAD_COORDINATE ;
		return false;
	}
	return true;
}

//Function returns true if coordinate is within the gameboard
bool Gameboard::checkCoordinate(int x, int y) const
{

	return  ((x >= 0 && y >= 0) && (x < boardSize_ && y < boardSize_));
}

