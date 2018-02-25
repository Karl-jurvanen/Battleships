#include "Game.h"
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;


Game::Game()
{
}

Game::~Game()
{
}

void Game::addShips()
{
}

void Game::shoot()
{
}

void Game::menu()
{
	const string valikkoTeksti =

		"Laivanupotuspeli\n"
		"=======================\n\n"
		"Valinnat:\n"
		"1) Syota laivat\n"
		"2) Pelaa\n"
		"3) Arvo sijainnit\n"
		"L) Lopeta\n\n"
		"Valintasi: ";

	string valinta;

	while (true)
	{
		cout << valikkoTeksti;
		getline(cin, valinta);

		if (valinta == "1")
		{
			cout << "Valittiin laivojen syotto." << endl;

		}

		else if (valinta == "2")
		{
			cout << "Valittiin pelaaminen." << endl;
		}

		else if (valinta == "3")
		{
			cout << "valittiin Sijaintien arpominen." << endl;
		}
		else if (valinta == "L" || valinta == "l")
		{
			break;
		}

		else
		{
			cout << "Virheellinen syote." << endl;
		}
	}
}
