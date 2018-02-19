#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Battleships/Ship.h"
#include "../Battleships/Gameboard.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod3)
		{
			std::stringstream oss;
			std::streambuf* p_cout_streambuf = std::cout.rdbuf();
			std::cout.rdbuf(oss.rdbuf());

			std::cout << "Hello" << std::endl;
			std::cout << "World" << std::endl;
			std::cout.rdbuf(p_cout_streambuf);

			Assert::IsTrue((oss && oss.str() == "Hello\nWorld\n"));
		}

		TEST_METHOD(Ship_Constructor_size)
		{

			for (int i = 2; i < 6; i++)
			{
			Ship ship(i);

			Assert::AreEqual(ship.getSize(), i);
			}
			

			
		}


	};
}