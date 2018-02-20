#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Battleships/Ship.h"
#include "../Battleships/Gameboard.h"
#include <iostream>

const string SHIP_ALREADY_THERE = "Ship already there.\n";
const string SHIP_OUT_OF_BOUNDS = "Ship goes off game board.\n";
const string BAD_COORDINATE = "Virheellinen koordinaatti.\n";


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
				Gameboard testgame1(i);

				Assert::AreEqual(i, testgame1.getBoardSize());
				
			}
			
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

			Gameboard game(6);

			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"    1 2 3 4 5 6 \n"
				"  ----------------\n"
				"A |              | A\n"
				"B |              | B\n"
				"C |              | C\n"
				"D |              | D\n"
				"E |              | E\n"
				"F |              | F\n"
				"  ----------------\n"
				"    1 2 3 4 5 6 \n";


			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_empty_7)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7);

			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"    1 2 3 4 5 6 7 \n"
				"  ------------------\n"
				"A |                | A\n"
				"B |                | B\n"
				"C |                | C\n"
				"D |                | D\n"
				"E |                | E\n"
				"F |                | F\n"
				"G |                | G\n"
				"  ------------------\n"
				"    1 2 3 4 5 6 7 \n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_empty_8)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(8);

			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"    1 2 3 4 5 6 7 8 \n"
				"  --------------------\n"
				"A |                  | A\n"
				"B |                  | B\n"
				"C |                  | C\n"
				"D |                  | D\n"
				"E |                  | E\n"
				"F |                  | F\n"
				"G |                  | G\n"
				"H |                  | H\n"
				"  --------------------\n"
				"    1 2 3 4 5 6 7 8 \n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_empty_9)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(9);

			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"    1 2 3 4 5 6 7 8 9 \n"
				"  ----------------------\n"
				"A |                    | A\n"
				"B |                    | B\n"
				"C |                    | C\n"
				"D |                    | D\n"
				"E |                    | E\n"
				"F |                    | F\n"
				"G |                    | G\n"
				"H |                    | H\n"
				"I |                    | I\n"
				"  ----------------------\n"
				"    1 2 3 4 5 6 7 8 9 \n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_one_ship_6)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(6);

			game.addShip(5, 1, "A1", "e");
			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"    1 2 3 4 5 6 \n"
				"  ----------------\n"
				"A | 5            | A\n"
				"B | 5            | B\n"
				"C | 5            | C\n"
				"D | 5            | D\n"
				"E | 5            | E\n"
				"F |              | F\n"
				"  ----------------\n"
				"    1 2 3 4 5 6 \n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_one_ship_7)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7);

			game.addShip(5,1,"A1","e");
			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected = 
				"    1 2 3 4 5 6 7 \n"
				"  ------------------\n"
				"A | 5              | A\n"
				"B | 5              | B\n"
				"C | 5              | C\n"
				"D | 5              | D\n"
				"E | 5              | E\n"
				"F |                | F\n"
				"G |                | G\n"
				"  ------------------\n"
				"    1 2 3 4 5 6 7 \n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_one_ship_8)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(8);

			game.addShip(5, 1, "A1", "e");
			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"    1 2 3 4 5 6 7 8 \n"
				"  --------------------\n"
				"A | 5                | A\n"
				"B | 5                | B\n"
				"C | 5                | C\n"
				"D | 5                | D\n"
				"E | 5                | E\n"
				"F |                  | F\n"
				"G |                  | G\n"
				"H |                  | H\n"
				"  --------------------\n"
				"    1 2 3 4 5 6 7 8 \n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Printships_one_ship_9)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(9);

			game.addShip(5, 1, "A1", "e");
			game.printShips();

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected =
				"    1 2 3 4 5 6 7 8 9 \n"
				"  ----------------------\n"
				"A | 5                  | A\n"
				"B | 5                  | B\n"
				"C | 5                  | C\n"
				"D | 5                  | D\n"
				"E | 5                  | E\n"
				"F |                    | F\n"
				"G |                    | G\n"
				"H |                    | H\n"
				"I |                    | I\n"
				"  ----------------------\n"
				"    1 2 3 4 5 6 7 8 9 \n";

			Assert::AreEqual(output, expected);
		}


		//Test output when user tries to add ship on top of another ship
		//Expected result is an error message
		TEST_METHOD(Gameboard_Overlapping_Ships_6)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(6);

			game.addShip(5, 1, "A1", "e");
			game.addShip(5, 1, "A1", "e");
			

			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected = SHIP_ALREADY_THERE;

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Overlapping_Ships_7)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7);

			game.addShip(5, 1, "A6", "e");
			game.addShip(5, 1, "C6", "e");


			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected = SHIP_ALREADY_THERE;

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Ship_Out_Of_Bounds_6)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(6);

			game.addShip(5, 1, "A6", "p");
			


			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected = SHIP_OUT_OF_BOUNDS;

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Ship_Out_Of_Bounds_7)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7);

			game.addShip(5, 1, "G7", "i");



			string output = oss.str();
			//Logger::WriteMessage(output);
			std::cout.rdbuf(p_cout_streambuf);

			string expected = "Ship goes off game board.\n";

			Assert::AreEqual(output, expected);
		}

		TEST_METHOD(Gameboard_Bad_Coordinate_7)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			Gameboard game(7);

			game.addShip(5, 1, "H7", "i");

			string output = oss.str();
			std::cout.rdbuf(p_cout_streambuf);

			string expected = "Virheellinen koordinaatti.\n";

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
	};
}