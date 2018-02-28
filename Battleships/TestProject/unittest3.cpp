#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Battleships/Game.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(game_menu_test)
		{
			Game testgame;

			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			std::streambuf* p_cin_streambuf = std::cin.rdbuf();
			std::stringstream input("3\n2\na1\np\nl\n");		//simulated user input
			//input << "l\n";
			std::cin.rdbuf(input.rdbuf());

			//	
		
			testgame.menu();

			string test;
			string output;
			while (! oss.eof())
			{
				oss >> test;
				output += test + "\n";

			}
			//test = oss.str();
			std::cout.rdbuf(p_cout_streambuf);
			std::cin.rdbuf(p_cin_streambuf);

			Assert::IsTrue((oss && oss.str() == "Hello\nWorld\n"));
		}
	};
}