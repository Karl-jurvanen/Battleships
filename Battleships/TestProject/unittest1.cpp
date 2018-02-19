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
				Gameboard testgame1(i);

				std::cerr << 10 << std::endl;

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

		TEST_METHOD(Gameboard_6_Printships_empty)
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



			Assert::IsTrue((oss && oss.str() == expected));
		}

		TEST_METHOD(Gameboard_7_Printships_empty)
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

			Assert::IsTrue((oss && oss.str() == expected));
		}

		TEST_METHOD(Gameboard_8_Printships_empty)
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

			Assert::IsTrue((oss && oss.str() == expected));
		}


		TEST_METHOD(Gameboard_6_Printships_one_ship)
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

			Assert::IsTrue((oss && oss.str() == expected));
		}

		TEST_METHOD(Gameboard_7_Printships_one_ship)
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

			Assert::IsTrue((oss && oss.str() == expected));
		}

		TEST_METHOD(Gameboard_8_Printships_one_ship)
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

			Assert::IsTrue((oss && oss.str() == expected));
		}

	};
}