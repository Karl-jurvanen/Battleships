#include "Game.h"
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;


Game::Game(): shipSizes_(4) ,board_()
{
	shipList_ = new int[4];
	for (int i = 0; i < 4; i++)
	{
		shipList_[i] = 1;
	}
	gameOver_ = 1;
}

Game::Game(int boardsize, int shipList[], int shipSizes, int shipCount): shipSizes_(shipSizes), shipCount_(shipCount),
		board_(boardsize, shipCount)
{
	shipList_ = new int[shipSizes];
	for (int i = 0; i < shipSizes_; i++)
	{
	shipList_[i] = shipList[i];

	}
	gameOver_ = 1;
}

Game::~Game()
{
	for (int i = 0; i < shipSizes_; i++)
	{
		cout << shipList_[i];
	}
	delete[] shipList_;
}

void Game::addShips()
{
	for (int i = 0; i < shipSizes_; i++)
	{
		for (int j = 0; j < shipList_[i]; j++)
		{
			while (true)
			{
				
				int sizeToAdd = shipSizes_ + 1 - i;
				string message = ADD_SHIP_START;
				string coordinate;
				string direction;
				switch (sizeToAdd)
				{
				case 2: cout << message.insert(5, "kahden");
					break;
				case 3: cout << message.insert(5, "kolmen");
					break;
				case 4: cout << message.insert(5, "neljan");
					break;
				case 5: cout << message.insert(5, "viiden");
					break;
				default:
					break;
				}
				getline(cin, coordinate);
				cout << ADD_SHIP_DIR;
				getline(cin, direction);
				if (board_.addShip(sizeToAdd, coordinate, direction))
					board_.printShips();
					break;
				
			}		
		}
	}
	gameOver_ = 0;
}

void Game::shoot()
{
	while (true)
	{
		string input;
		cout << SHOOT_COORD;
		getline(cin, input);
		if (input == "")
		{
			cout << BAD_INPUT;
			continue;
		}
		else if (input.at(0) == 'p' || input.at(0) == 'P')
		{
			break;
		}
		else if (input == "\\@")
		{
			board_.printShips();
			continue;
		}
		board_.shoot(input);
		board_.printShots();
	}
}

void Game::menu()
{
	const string menuText =

		"Laivanupotuspeli\n"
		"=======================\n\n"
		"Valinnat:\n"
		"1) Syota laivat\n"
		"2) Pelaa\n"
		"3) Arvo sijainnit\n"
		"L) Lopeta\n\n"
		"Valintasi: ";

	string userChoise;

	while (true)
	{
		cout << menuText;
		getline(cin, userChoise);

		if (userChoise == "1")
		{
			board_.initialize();
			addShips();
		}

		else if (userChoise == "2")
		{
			if (gameOver_ != 0)
			{
				cout << SHIPS_NOT_SET;
			}
			else
			{
				shoot();
			}
		}

		else if (userChoise == "3")
		{
			cout << "valittiin Sijaintien arpominen." << endl;
		}
		else if (userChoise == "L" || userChoise == "l")
		{
			break;
		}

		else
		{
			cout << "Virheellinen syote." << endl;
		}
	}
}
