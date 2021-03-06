#include "Game.h"
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

using std::ofstream;
using std::ios;

Game::Game(): shipSizes_(4) ,board_()
{
	srand(static_cast<unsigned int>(time(NULL)));
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
	srand(static_cast<unsigned int>(time(NULL)));
	shipList_ = new int[shipSizes_];
	for (int i = 0; i < shipSizes_; i++)
	{
		shipList_[i] = shipList[i];
	}
	gameOver_ = 1;
}

Game::~Game()
{
	delete[] shipList_;
}

void Game::addShips()
{
	//step through shipList[] array that contains number of ships of each size that needs to be added to gameboard
	//for example game with {1,2,3,4} ships  has 1 five-length ship and 4 two-length ships
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

				//insert in the print out the correct word for ship size
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
				case 6: cout << message.insert(5, "kuuden");
					break;
				case 7: cout << message.insert(5, "seitseman");
					break;
				case 8: cout << message.insert(5, "kahdeksan");
					break;
				case 9: cout << message.insert(5, "yhdeksan");
					break;
				case 10: cout << message.insert(5, "kymmenen");
					break;
				case 11: cout << message.insert(5, "yhdentoista");
					break;
				case 12: cout << message.insert(5, "kahdentoista");
					break;
				case 13: cout << message.insert(5, "kolmentoista");
					break;
				default:
					break;
				}
				getline(cin, coordinate);
				cout << ADD_SHIP_DIR;
				getline(cin, direction);

				int result = board_.addShip(sizeToAdd, coordinate, direction);

				//Check result, if not succesfull continue loop to ask user to try again
				if (result == 0) //success
				{
					board_.printShips();
					break;
				}
				else if (result == 1)
				{
					cout << BAD_DIRECTION;
				}
				else if (result == 2)
				{
					cout << SHIP_OUT_OF_BOUNDS;
				}
				else if (result == 3)
				{
					cout << SHIP_ALREADY_THERE;
				}
			}		
		}
	}
	//game can now be started
	gameOver_ = 0;
}

void Game::addShipsRandom()
{
	//use system time to generate random number 
	//cast to unsigned int to avoid build warnings
	
	for (int i = 0; i < shipSizes_; i++)
	{
		for (int j = 0; j < shipList_[i]; j++)
		{
			while (true)
			{
				int sizeToAdd = shipSizes_ + 1 - i;
				int x;
				int y;
				int dir;
				string direction;

				x = rand() % (board_.getBoardSize() );
				y = rand() % (board_.getBoardSize() );
				dir = rand() % 4;

				switch (dir)
				{
				case 0: direction = "p";
					break;
				case 1: direction = "i";
					break;
				case 2: direction = "e";
					break;
				case 3: direction = "l";
					break;
				}

				if (board_.addShip(sizeToAdd, x, y, direction) == 0)
				{
					break;
				}
			}
		}
	}
	board_.printShips();
	gameOver_ = 0;
}

void Game::shoot()
{
	string input;

	while (true)
	{
		//Skip printing shots if user asked for ship locations last to avoid double printing
		if (input != "\\@")
		{
			board_.printShots();
		}
		
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
		string printout;
		board_.shoot(input, printout);
		cout << printout;

		if (board_.checkGameOver())
		{
			board_.printShots();
			cout << "Peli loppui.\n\n";
			gameOver_ = 1;
			break;
		}
	}
}

void Game::shootRandom()
{
	//srand(static_cast<unsigned int>(time(NULL)));

	int x;
	int y;

	board_.printShots();

	while (true)
	{
		x = rand() % (board_.getBoardSize() );
		y = rand() % (board_.getBoardSize() );

		if (board_.shoot(x, y) != 3) // successfull shot
		{
			board_.printShots();
			Sleep(500);
		}

		if (board_.checkGameOver())
		{
			board_.printShots();
			cout << "Peli loppui.\n\n";
			gameOver_ = 1;
			break;
		}
	}
	
}

int Game::shootRandomStatistics()
{
	int shotsTaken = 0; // keep track of number of shots 
	int x;
	int y;
	while (true)
	{
		x = rand() % (board_.getBoardSize());
		y = rand() % (board_.getBoardSize());
		if (board_.shoot(x, y) != 3) // successfull shot
		{
			shotsTaken++;
		}
		
		if (board_.checkGameOver())
		{
			gameOver_ = 1;
			return shotsTaken;
		}
	}

}

int Game::shootAI()
{
	int shotsTaken = 0; // keep track of number of shots 
	board_.printShots();
	while (true)
	{
		int x = 0;
		int y = 0;

		board_.calculateValues(x, y);

		if (board_.shoot(x, y) != 3) // successfull shot
		{
			system("cls");

			board_.printShots();
			shotsTaken++;
			Sleep(500);
		}

		if (board_.checkGameOver())
		{
			board_.printShots();
			cout << "Peli loppui.\n\n";
			gameOver_ = 1;
			return shotsTaken;
		}
	}
}

int Game::shootAIStatistics()
{
	int shotsTaken = 0; // keep track of number of shots 
	
	while (true)
	{
		int x = 0;
		int y = 0;

		board_.calculateValues(x, y);

		if (board_.shoot(x, y) != 3) // successfull shot
		{		
			shotsTaken++;

		}
		if (board_.checkGameOver())
		{		
			gameOver_ = 1;
			return shotsTaken;
		}
	}
}

void Game::simulateShooting(int simulationtimes, string logfile)
{
	ofstream statisticFile(logfile, ios::out);

	const string menuText =

		"Simulointi - Anna ampumisalgoritmi\n"
		"=======================\n\n"
		"Valinnat:\n"
		"1) Satunnainen\n"
		"2) algoritmi\n";

	string userChoise;


	cout << menuText;
	getline(cin, userChoise);

	

	if (!statisticFile)
	{
		cout << "File could not be opened" << endl;
		return;
	}

	for (int i = 0; i < simulationtimes; i++)
	{
		board_.initialize();
		addShipsRandom();
		if (userChoise == "1")
		{
			statisticFile << shootRandomStatistics() << endl;
		}
		if (userChoise == "2")
		{
			statisticFile << shootAIStatistics() << endl;
		}
	}
	return;
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
		"4) Simuloi ampuminen\n"
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
			//user has not placed the ships on gameboard yet, don't allow shooting
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
			board_.initialize();
			addShipsRandom();
		}
		else if (userChoise == "4")
		{
			if (gameOver_ != 0)
			{
				cout << SHIPS_NOT_SET;
			}
			else
			{
				//shootRandom();
				shootAI();
			}
		}

		else if (userChoise == "5") // hidden statistical testing
		{

			cout << "Anna simulointikerrat: ";
			getline(cin, userChoise);
			int simulateTimes = 0;


			try
			{
				simulateTimes = stoi(userChoise);
			}
			catch (const std::exception&)
			{
				cout << "Anna kokonaisluku." << endl;
			}

			simulateShooting(simulateTimes, "statistics.txt");

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
