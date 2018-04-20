#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Battleships/Ship.h"
#include "../Battleships/Gameboard.h"
#include <iostream>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(Gameboard_constructor_boardsize)
		{
			int test1 = 10;
			
			for (int i = 5; i < 13; i++)
			{
				Gameboard testgame1(i,4);

				Assert::AreEqual(i, testgame1.getBoardSize());
				
			}
			
		}

		TEST_METHOD(Gameboard_initialize)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7,1);

			game.addShip(5,"a1","e");
			game.initialize();
			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"Laivat sijaitsevat seuraavissa paikoissa:\n\n"
				"    1 2 3 4 5 6 7 \n"
				"  -----------------\n"
				"A |               | A\n"
				"B |               | B\n"
				"C |               | C\n"
				"D |               | D\n"
				"E |               | E\n"
				"F |               | F\n"
				"G |               | G\n"
				"  -----------------\n"
				"    1 2 3 4 5 6 7 \n\n";
			
			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(TestMethod2)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			std::cout << "Hello" << std::endl;
			std::cout << "World" << std::endl;
			std::cout.rdbuf(p_cout_streambuf);

			Assert::IsTrue((oss && oss.str() == "Hello\nWorld\n"));
		}

		TEST_METHOD(Gameboard_Printships_empty_6)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(6,1);

			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"Laivat sijaitsevat seuraavissa paikoissa:\n\n"
				"    1 2 3 4 5 6 \n"
				"  ---------------\n"
				"A |             | A\n"
				"B |             | B\n"
				"C |             | C\n"
				"D |             | D\n"
				"E |             | E\n"
				"F |             | F\n"
				"  ---------------\n"
				"    1 2 3 4 5 6 \n\n";


			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_empty_7)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7,1);

			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"Laivat sijaitsevat seuraavissa paikoissa:\n\n"
				"    1 2 3 4 5 6 7 \n"
				"  -----------------\n"
				"A |               | A\n"
				"B |               | B\n"
				"C |               | C\n"
				"D |               | D\n"
				"E |               | E\n"
				"F |               | F\n"
				"G |               | G\n"
				"  -----------------\n"
				"    1 2 3 4 5 6 7 \n\n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_empty_8)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(8,1);

			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"Laivat sijaitsevat seuraavissa paikoissa:\n\n"
				"    1 2 3 4 5 6 7 8 \n"
				"  -------------------\n"
				"A |                 | A\n"
				"B |                 | B\n"
				"C |                 | C\n"
				"D |                 | D\n"
				"E |                 | E\n"
				"F |                 | F\n"
				"G |                 | G\n"
				"H |                 | H\n"
				"  -------------------\n"
				"    1 2 3 4 5 6 7 8 \n\n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_empty_9)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(9,1);

			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"Laivat sijaitsevat seuraavissa paikoissa:\n\n"
				"    1 2 3 4 5 6 7 8 9 \n"
				"  ---------------------\n"
				"A |                   | A\n"
				"B |                   | B\n"
				"C |                   | C\n"
				"D |                   | D\n"
				"E |                   | E\n"
				"F |                   | F\n"
				"G |                   | G\n"
				"H |                   | H\n"
				"I |                   | I\n"
				"  ---------------------\n"
				"    1 2 3 4 5 6 7 8 9 \n\n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_one_ship_6)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(6,1);

			game.addShip(5,  "A1", "e");
			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"Laivat sijaitsevat seuraavissa paikoissa:\n\n"
				"    1 2 3 4 5 6 \n"
				"  ---------------\n"
				"A | 5           | A\n"
				"B | 5           | B\n"
				"C | 5           | C\n"
				"D | 5           | D\n"
				"E | 5           | E\n"
				"F |             | F\n"
				"  ---------------\n"
				"    1 2 3 4 5 6 \n\n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_one_ship_7)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7,1);

			game.addShip(5, "A1","e");
			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected = 
				"Laivat sijaitsevat seuraavissa paikoissa:\n\n"
				"    1 2 3 4 5 6 7 \n"
				"  -----------------\n"
				"A | 5             | A\n"
				"B | 5             | B\n"
				"C | 5             | C\n"
				"D | 5             | D\n"
				"E | 5             | E\n"
				"F |               | F\n"
				"G |               | G\n"
				"  -----------------\n"
				"    1 2 3 4 5 6 7 \n\n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_one_ship_8)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(8,1);

			game.addShip(5,  "A1", "e");
			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"Laivat sijaitsevat seuraavissa paikoissa:\n\n"
				"    1 2 3 4 5 6 7 8 \n"
				"  -------------------\n"
				"A | 5               | A\n"
				"B | 5               | B\n"
				"C | 5               | C\n"
				"D | 5               | D\n"
				"E | 5               | E\n"
				"F |                 | F\n"
				"G |                 | G\n"
				"H |                 | H\n"
				"  -------------------\n"
				"    1 2 3 4 5 6 7 8 \n\n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_one_ship_9)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(9,1);

			game.addShip(5, "A1", "e");
			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"Laivat sijaitsevat seuraavissa paikoissa:\n\n"
				"    1 2 3 4 5 6 7 8 9 \n"
				"  ---------------------\n"
				"A | 5                 | A\n"
				"B | 5                 | B\n"
				"C | 5                 | C\n"
				"D | 5                 | D\n"
				"E | 5                 | E\n"
				"F |                   | F\n"
				"G |                   | G\n"
				"H |                   | H\n"
				"I |                   | I\n"
				"  ---------------------\n"
				"    1 2 3 4 5 6 7 8 9 \n\n";

			Assert::AreEqual(output, expected);
		}


		//Test output when user tries to add ship on top of another ship
		//Expected result is an error message
		TEST_METHOD(Gameboard_Overlapping_Ships_6)
		{			
			Gameboard game(6,2);
			game.addShip(5, "A1", "e");
			int output = game.addShip(5, "A1", "e");			
			Assert::AreEqual(output, 3);
		}

		TEST_METHOD(Gameboard_Overlapping_Ships_7)
		{
			Gameboard game(7,2);
			game.addShip(5, "A6", "e");
			int output = game.addShip(5, "C6", "e");
			Assert::AreEqual(output, 3);
		}

		TEST_METHOD(Gameboard_Ship_Out_Of_Bounds_6)
		{
			Gameboard game(6,2);

			int output = game.addShip(5, "A6", "p");
			Assert::AreEqual(output, 2);
		}

		TEST_METHOD(Gameboard_Ship_Out_Of_Bounds_7)
		{
			Gameboard game(7,2);

			int output = game.addShip(5, "G7", "i");
			Assert::AreEqual(output, 2);
		}

		TEST_METHOD(Gameboard_Bad_Coordinate_7)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7,2);

			game.addShip(5, "H7", "i");

			string output = oss.str();
			std::cout.rdbuf(p_cout_streambuf);

			string expected = "Virheellinen koordinaatti.\n\n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(cin_test)
		{
			// For testing functions with user inputs.
			// redirecting cin buffer to stringstream so the test can simulate user input
			std::streambuf* p_cin_streambuf = std::cin.rdbuf();
			std::stringstream input("testing\nasdasdasd");

			std::cin.rdbuf(input.rdbuf());

			string test;

			std::getline(std::cin, test);
			std::getline(std::cin, test);

			std::cin.rdbuf(p_cin_streambuf);
		}

		TEST_METHOD(Gameboard_shoot_miss)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7,2);

			game.addShip(5, "A1", "e");
			string coordinate = "B2";
			game.shoot(coordinate);

			string output = oss.str();

			std::cout.rdbuf(p_cout_streambuf);

			string expected = MISSED_SHIP;
			expected.insert(17, coordinate);
			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_shoot_hit)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7,1);

			game.addShip(5, "A1", "e");
			string coordinate = "A1";
			game.shoot(coordinate);

			string output = oss.str();

			std::cout.rdbuf(p_cout_streambuf);

			string expected = "\nLaukaus kohtaan A1 osui laivaan.\n\n";
			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_shoot_sink)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7,1);

			game.addShip(2, "A1", "e");
			string coordinate = "A1";
			game.shoot(coordinate);
			game.shoot("B1");

			string output = oss.str();

			std::cout.rdbuf(p_cout_streambuf);

			string expected =	"\nLaukaus kohtaan A1 osui laivaan.\n\n"
								"\nLaukaus kohtaan B1 upotti laivan.\n\n";
			Assert::AreEqual(output, expected);
		}
	};
}