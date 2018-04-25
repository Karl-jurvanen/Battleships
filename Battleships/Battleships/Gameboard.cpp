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
	values_ = new int*[boardSize_];
	for (int i = 0; i < boardSize_; i++)
	{
		shots_[i] = new char[boardSize_];
		ships_[i] = new int[boardSize_];
		values_[i] = new int[boardSize_];
	}

	//Initialize both gameboards to empty
	initialize();
}

Gameboard::Gameboard():boardSize_(7), shipCount_(4), shipsAdded_(0), shipsSunk_(0)
{
	shiplist_ = new Ship[shipCount_];

	shots_ = new char*[boardSize_];
	ships_ = new int*[boardSize_];
	values_ = new int*[boardSize_];
	for (int i = 0; i < boardSize_; i++)
	{
		shots_[i] = new char[boardSize_];
		ships_[i] = new int[boardSize_];
		values_[i] = new int[boardSize_];
	}
	initialize();
}


Gameboard::~Gameboard()
{
	for (int i = 0; i < boardSize_; i++)
	{
		delete[] shots_[i];
		delete[] ships_[i];
		delete[] values_[i];
	}
	delete[] shots_;
	delete[] ships_;
	delete[] shiplist_;
	delete[] values_;
}

char ** Gameboard::getShots() const
{
	return shots_;
}

int ** Gameboard::getShips() const
{
	return ships_;
}

int ** Gameboard::getValues() const
{
	return values_;
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
			shots_[i][j] = ' ';
			ships_[i][j] = -1;
			values_[i][j] = 0;
		}
	}
	shipsAdded_ = 0;
	shipsSunk_ = 0;
	for (int i = 0; i < shipCount_; i++)
	{
		shiplist_[i] = Ship();	
	}
	return;
}

/*
return 0 for succesfully added, 
1 for unknown direction, 
2 for ship going off board
3 for ship clipping another ship 
*/
int Gameboard::addShip(int shipSize,  string coord, string dir)
{
	int x;
	int y;
	if (parseCoordinates(x, y, coord))
	{
		return addShip(shipSize, x, y, dir);
	}
	return 1;
}

int Gameboard::addShip(int shipSize, int x, int y, string dir)
{
	if (dir == "p")
	{
		for (int i = 0; i < shipSize; i++)
		{
			if (!checkCoordinate(x, (y - i)))
			{
				//cout << SHIP_OUT_OF_BOUNDS;
				return 2;
			}
			if (ships_[x][y - i] != -1)
			{
				//cout << SHIP_ALREADY_THERE;
				return 3;
			}

		}
		shiplist_[shipsAdded_].setSize(shipSize);
		for (int i = 0; i < shipSize; i++)
		{
			ships_[x][y - i] = shipsAdded_;
		}
		shipsAdded_++;
		return 0;

	}

	else if (dir == "i")
	{
		for (int i = 0; i < shipSize; i++)
		{
			if (!checkCoordinate((x + i), y))
			{
				//cout << SHIP_OUT_OF_BOUNDS;
				return 2;
			}
			if (ships_[x + i][y] != -1)
			{
				//cout << SHIP_ALREADY_THERE;
				return 3;
			}

		}
		shiplist_[shipsAdded_].setSize(shipSize);
		for (int i = 0; i < shipSize; i++)
		{
			ships_[x + i][y] = shipsAdded_;
		}
		shipsAdded_++;
		return 0;
	}

	else if (dir == "e")
	{
		for (int i = 0; i < shipSize; i++)
		{
			if (!checkCoordinate(x, (y + i)))
			{
				//cout << SHIP_OUT_OF_BOUNDS;
				return 2;
			}
			if (ships_[x][y + i] != -1)
			{
				//cout << SHIP_ALREADY_THERE;
				return 3;
			}

		}
		shiplist_[shipsAdded_].setSize(shipSize);
		for (int i = 0; i < shipSize; i++)
		{
			ships_[x][y + i] = shipsAdded_;
		}
		shipsAdded_++;
		return 0;
	}

	else if (dir == "l")
	{
		for (int i = 0; i < shipSize; i++)
		{
			if (!checkCoordinate((x - i), y))
			{
				//cout << SHIP_OUT_OF_BOUNDS;
				return 2;
			}
			if (ships_[x - i][y] != -1)
			{
				//cout << SHIP_ALREADY_THERE;
				return 3;
			}

		}
		shiplist_[shipsAdded_].setSize(shipSize);
		for (int i = 0; i < shipSize; i++)
		{
			ships_[x - i][y] = shipsAdded_;
		}
		shipsAdded_++;
		return 0;
	}
	else
	{
		cout << "Virheellinen suunta." << endl;
		return 1;
	}
}


//Shoot function retuens true if shooting is succesfull (hit or miss)
//and returns false if shooting failed (illegal coordinate or shooting in the same spot again)
bool Gameboard::shoot(string coord, string& message)
{
	int x;
	int y;
	string output;
	if (parseCoordinates(x, y, coord))
	{
		int result = shoot(x, y);

		switch (result)
		{
		case 0:
			output = MISSED_SHIP;
			message = output.insert(17, coord);
			return true;
		case 1:
			output = HIT_SHIP;
			message = output.insert(17, coord);
			return true;
		case 2:
			output = SUNK_SHIP;
			message = output.insert(17, coord);
			return true;
		case 3:
			output = ALREADY_SHOT_THERE;
			message = output.insert(9, coord);
			return false;
		}
		//check if we the coordinate has already been shot at
	}
	return false;
}

/**
return 
0 for miss
1 for hit
2 for sunk ship
3 for already shot there
*/
int Gameboard::shoot(int x, int y)
{
	if (shots_[x][y] != ' ')
	{
		return 3; //have already shot there
	}
	else
	{
		//Check if there is ship there
		if (ships_[x][y] == -1)
		{
			shots_[x][y] = 'X';
			return 0; // miss
		}
		else
		{
			int target = ships_[x][y];
			shiplist_[target].hit();
			//Check if the target that was hit sinks 
			if (shiplist_[target].getHits() == shiplist_[target].getSize())
			{
				sinkShip(target);
				return 2; // ship sunk
			}
			else
				//Ship was hit but it did not sink
			{
				shots_[x][y] = '*';
			}
			return 1; // ship hit
		}
	}
}

void Gameboard::sinkShip(int shipIndex)
{
	//Loop through shots_ and change value to # where ships_ == shipindex
	
	for (int y = 0; y < boardSize_; y++)
	{
		for (int x = 0; x < boardSize_; x++)
		{
			if (ships_[x][y] == shipIndex)
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

		cout << "| " << column << endl;
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

		cout << "| " << column << endl;
		column++;
	}

	printFooter();
}

//calculate a value for each coordinate. Higher value means better chance of hitting a ship
//also find the best value 
int Gameboard::calculateValues(int & x, int & y)
{
	int bestValue = -1000;
	for (int j = 0; j < boardSize_; j++)
	{
		for (int i = 0; i < boardSize_; i++)
		{
			values_[i][j] = 0; // zero the previous calculation

			//give heavjy penalty if coordinate has been shot at already
			if ((shots_[i][j] == '#') || (shots_[i][j] == '*') || (shots_[i][j] == 'X'))
			{
				values_[i][j] = -10000;
			}

			//change value based on neighbors
			values_[i][j] += checkNeighbors(i, j);

			if (values_[i][j] > bestValue)
			{
				//update the coordinate of best value
				bestValue = values_[i][j];
				x = i;
				y = j;
			}
		}
	}
	//return the best value and the coordinate as references
	return bestValue;
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

	for (int i = 0; i < boardSize_ * 2 + 3; i++)
	{
		cout << "-";
	}
	cout << endl;
}

//Function that prints the bottom rows of gameboard
void Gameboard::printFooter() const
{
	cout << "  ";
	for (int i = 0; i < boardSize_ * 2 + 3; i++)
	{
		cout << "-";
	}

	cout << endl << "    ";
	for (int i = 1; i <= boardSize_; i++)
	{
		cout << i << " ";
	}
	cout << endl << endl;
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

int Gameboard::checkNeighbors(int x, int y)
{
	int value = 0;

	if (checkCoordinate(x, y+1))	//south neighbor
	{
		int thisvalue = getNeighborValue(x, y + 1);

		value += thisvalue;


		if (thisvalue == 400) //check if two hits in a row
		{
			if (checkCoordinate(x , y + 2))
			{
				if (getNeighborValue(x, y + 2) == 400)
				{
					value += 3000;
				}
			}
		}
		 
	}

	if (checkCoordinate(x, y - 1))	//north neighbor
	{

		int thisvalue = getNeighborValue(x, y - 1);
		value += thisvalue;


		if (thisvalue == 400) //check if two hits in a row
		{
			if (checkCoordinate(x , y - 2))
			{
				if (getNeighborValue(x, y - 2) == 400)
				{
					value += 3000;
				}
			}
		}
	}

	if (checkCoordinate(x +1, y )) // east neighbor
	{

		int thisvalue = getNeighborValue(x + 1, y);
		value += thisvalue;


		if (thisvalue == 400) //check if two hits in a row
		{
			if (checkCoordinate(x + 2, y))
			{
				if (getNeighborValue(x +2, y) == 400)
				{
					value += 3000;
				}
			}
		}  

	}

	if (checkCoordinate(x -1, y)) // west neighbor
	{

		int thisvalue = getNeighborValue(x - 1, y);

		value += thisvalue;


		if (thisvalue == 400) //check if two hits in a row
		{
			if (checkCoordinate(x - 2, y))
			{
				if (getNeighborValue(x - 2 , y ) == 400)
				{
					value += 3000;
				}
			}
		}
	}

	return value;
}

int Gameboard::getNeighborValue(int x, int y)
{
	//Reduce value if neighbor is 'X' or '#'
	//increase if neighbor is '*'
	if (shots_[x][y] == 'X')
	{
		return -100;
	}
	else if (shots_[x][y] == '*')
	{
		return 400;
	}
	else if (shots_[x][y] == '#')
	{
		return -100;
	}
	else if (shots_[x][y] == ' ')
	{
		return 1;
	}
	return 0;
}

