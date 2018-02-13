#pragma once
#include <vector>

using std::vector;



class Ship
{
public:
	Ship();
	Ship(int size);



	~Ship();



private:

	int size_;
	int hits_;
};

