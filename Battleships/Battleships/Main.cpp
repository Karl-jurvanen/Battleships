#include "Gameboard.h"
#include "Game.h"
#include "Ship.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::getline;




int main()
{
	string input;

	cout << "Anna kentan sivu";
	getline(cin, input);
	int size;
	try
	{
		size = stoi(input);

	}
	catch (const std::invalid_argument&)
	{
		//catch possible exception from converting the string to int
		cout << "Virheellinen syote." << endl;
		return false;
	}
	int laivat[4] = { 2,1,0,3 };
	Game testgame(size, laivat, 4 , 6);
	//Game testgame;
	testgame.menu();

	//Gameboard game2(9,4);
	//
	//game2.printShips();
	//game2.addShip(5, "G6", "p");
	//game2.printShips();
	//game2.addShip(4, "G5", "l");
	//game2.printShips();
	//game2.addShip(4, "e1", "e");
	//game2.printShips();
	//game2.addShip(4, "A1", "e");
	//game2.printShips();
	//
   	//
	//while (true)
	//{
	//	string input;
	//
	//	if (input == "\\@")
	//	{
	//		game2.printShips();		
	//	}
	//	else if (input == "n")
	//	{
	//		//Zero the gameboard for a new game
	//		game2.initialize();
	//		game2.addShip(4, "G5", "l");
	//	}
	//	else
	//	{
	//		game2.shoot(input);
	//		game2.printShots();
	//	}
	//}
	//
	//game2.printShots();
	system("pause");
}