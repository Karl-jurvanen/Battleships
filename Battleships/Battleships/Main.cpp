#include "Gameboard.h"
#include "Game.h"
#include "Ship.h"

#include <iostream>
#include <sstream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::getline;

using std::ifstream;
using std::istringstream;

bool readSettings(string settingsFile, int& boardsize, int*& ships, int& longest);



int main()
{
	int boardsize;
	int* ships;
	int longestShip = 0;

	//if config file is not found or is broken, start game with default settings
	if (!readSettings("laiva.txt", boardsize, ships, longestShip))
	{
		Game testgame;
		testgame.menu(); // begin game
	}
	else // readSettings was succesful in getting configurations
	{
		int shipCount = 0;
		for (int i = 0; i < longestShip - 1; i++)
		{
			shipCount += ships[i];
		}

		Game testgame(boardsize, ships, longestShip - 1, shipCount);

		delete[] ships; // array that was used for reading config file is no longer needed
		testgame.menu(); // begin game
	}
}




bool readSettings(string settingsFile, int& boardsize, int*& ships, int& longest)
{
	string line;
	ifstream file(settingsFile);
	int flag = 0; // flag for checking if dynamic memory is allocated. is used for deleting it if function fails

	if (!file.is_open())
	{
		return false;
	}

	while (getline(file, line))
	{
		if (line[0] == '#') // skip comment
		{
			continue;
		}
		else
		{
			try
			{
				string contents[10];
				istringstream ss(line);

				int count = 0;
				//parse each row, delimited with whitespace
				while (getline(ss, contents[count], ' '))
				{
					count++;
				}
				if (contents[0] == "pelikentan_sivu:")
				{
					try
					{
						boardsize = stoi(contents[1]);
					}
					//catch possible exception from converting the string to int
					catch (const std::invalid_argument&)
					{
						if (flag == 1) { delete[] ships; }//delete possible dynamic memory before returning 
						file.close();
						return false;
					}
				}

				else if (contents[0] == "laivat:")
				{
					int sizes[20] = { 0 };
					int amounts[20] = { 0 };

					//find the longest ship listed in file
					//in case user has not given them in order
					int longest_ship = 0;
					size_t test = 0;

					for (int j = 0; j < count - 1; j++)
					{
						string pair = contents[j + 1];
						test = pair.find(':');
						int len = 0;
						int num = 0;

						try
						{
							//Get the shiplength and number from the pair eg. 12:3
							len = stoi(pair.substr(0, test));
							num = stoi(pair.substr(test + 1));
						}
						catch (const std::exception&)
						{
							if (flag == 1) { delete[] ships; }
							file.close();
							return false;
						}


						sizes[j] = len;
						amounts[j] = num;

						if ((sizes[j]) > longest_ship)
						{
							longest_ship = sizes[j];
						}
					}
					//use longest ship information to create correct size array of ship sizes
					//if input ships are 5:2 4:1 2:3
					//output array will be {2,1,0,3}
					//this array is later used for gameboard constructor

					int arraySize = longest_ship - 1;
					ships = new int[arraySize];
					flag = 1;
					for (int j = 0; j < arraySize; j++)
					{
						ships[j] = 0;
					}

					for (int i = 0; i < count - 1; i++)
					{
						//ships[] array has shipcounts with longest ship in game at index 0.
						//to get index of current pair (eg. 5:2)
						int shipIndex = longest_ship - sizes[i];
						int shipCount = amounts[i];
						ships[shipIndex] = shipCount;
					}

					longest = longest_ship;

				}
			}

			//assume that the file is bad if any exceptions are thrown
			catch (const std::exception&)
			{
				cout << "Virhe asetustiedostossa." << endl;

				if (flag == 1) { delete[] ships; }
				file.close();
				return false;
			}
		}
	}

	//file did not set shipcount or boardsize
	if (longest == 0 || boardsize == 0 || longest > boardsize)
	{
		if (flag == 1) { delete[] ships; }
		file.close();
		return false;
	}
	file.close();
	return true;
}